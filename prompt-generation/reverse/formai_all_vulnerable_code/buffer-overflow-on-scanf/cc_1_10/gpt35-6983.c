//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1000              // Maximum log size to prevent overflow
#define MAX_IP_ADDRESSES 100           // Maximum number of allowed IP addresses
#define MAX_FAILED_LOGIN_ATTEMPTS 3    // Maximum number of failed login attempts allowed before locking out an IP address
#define LOCKOUT_DURATION 300           // Lockout duration in seconds

// Structure to hold the logged information about an IP address
typedef struct {
    char address[15];   // IP address as a string
    time_t last_access; // Last access time
    int failed_attempts; // Number of failed login attempts
} AddressInfo;

// Function to check if an IP address is present in the list of allowed addresses
int is_ip_allowed(char *ip_address, AddressInfo *allowed_addresses, int num_allowed_addresses) {
    for (int i = 0; i < num_allowed_addresses; i++) {
        if (strcmp(ip_address, allowed_addresses[i].address) == 0) {
            return 1; // IP address found in list of allowed addresses
        }
    }

    return 0; // IP address not found in list of allowed addresses
}

// Function to add an IP address to the list of allowed addresses
void add_allowed_address(char *ip_address, AddressInfo *allowed_addresses, int *num_allowed_addresses) {
    strcpy(allowed_addresses[*num_allowed_addresses].address, ip_address);
    allowed_addresses[*num_allowed_addresses].last_access = time(NULL);
    allowed_addresses[*num_allowed_addresses].failed_attempts = 0;
    (*num_allowed_addresses)++;
}

// Function to log a failed login attempt
void log_failed_login_attempt(char *ip_address, AddressInfo *allowed_addresses, int num_allowed_addresses) {
    time_t current_time = time(NULL);
    int ip_found = 0; // Flag to indicate whether the IP address is found in the list of allowed addresses

    // Check if IP address is found in list of allowed addresses
    for (int i = 0; i < num_allowed_addresses; i++) {
        if (strcmp(ip_address, allowed_addresses[i].address) == 0) {
            ip_found = 1;
            allowed_addresses[i].last_access = current_time;
            allowed_addresses[i].failed_attempts++;
            printf("Failed login attempt from %s. Failed attempts: %d.\n", ip_address, allowed_addresses[i].failed_attempts);

            if (allowed_addresses[i].failed_attempts >= MAX_FAILED_LOGIN_ATTEMPTS) {
                printf("Too many failed login attempts from %s. IP address has been locked out for %d seconds.\n", ip_address, LOCKOUT_DURATION);
                allowed_addresses[i].last_access += LOCKOUT_DURATION;
                allowed_addresses[i].failed_attempts = 0;
            }

            break;
        }
    }

    // If IP address is not found in list of allowed addresses, add it
    if (!ip_found) {
        add_allowed_address(ip_address, allowed_addresses, &num_allowed_addresses);
        printf("Failed login attempt from new IP address %s. IP address has been added to the allowed list.\n", ip_address);
    }
}

int main() {
    AddressInfo allowed_addresses[MAX_IP_ADDRESSES]; // Array to hold the list of allowed IP addresses
    int num_allowed_addresses = 0; // Number of allowed IP addresses

    while (1) {
        char ip_address[15]; // Buffer to hold the IP address of the incoming connection
        printf("Enter incoming IP address: ");
        scanf("%s", ip_address);

        // Check if IP address is present in list of allowed addresses
        if (is_ip_allowed(ip_address, allowed_addresses, num_allowed_addresses)) {
            printf("Allowed connection from %s.\n", ip_address);
            allowed_addresses[num_allowed_addresses].last_access = time(NULL);
        }
        else {
            log_failed_login_attempt(ip_address, allowed_addresses, num_allowed_addresses);
        }

        // Check for outdated IP addresses and remove them from the list
        time_t current_time = time(NULL);
        for (int i = 0; i < num_allowed_addresses; i++) {
            if (current_time - allowed_addresses[i].last_access > LOCKOUT_DURATION) {
                printf("IP address %s has been removed from the list of allowed addresses.\n", allowed_addresses[i].address);
                num_allowed_addresses--;
                allowed_addresses[i] = allowed_addresses[num_allowed_addresses]; // Move last element to current position
                i--; // Decrement i to ensure all elements are checked
            }
        }

        // Check if log size has exceeded limit and remove oldest entry to prevent overflow
        if (num_allowed_addresses > MAX_LOG_SIZE) {
            printf("Maximum log size reached. Oldest IP address has been removed from the list.\n");
            num_allowed_addresses--;
            for (int i = 0; i < num_allowed_addresses; i++) {
                allowed_addresses[i] = allowed_addresses[i+1];
            }
        }
    }

    return 0;
}