//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100
#define MAX_EVENTS 1000

typedef struct {
    char name[30];
    char password[30];
    int login_attempts;
    int is_locked;
} User;

typedef struct {
    char ip_address[20];
    char username[30];
    char password[30];
    int timestamp;
} Event;

int is_valid_ip_address(char *ip_address) {
    // checks if the string is a valid IP address
    int i, num_parts = 0;
    char *part;
    for (part = strtok(ip_address, "."); part; part = strtok(NULL, ".")) {
        if (!isdigit(*part) || atoi(part) < 0 || atoi(part) > 255) {
            return 0;
        }
        num_parts += 1;
    }
    return num_parts == 4;
}

void print_events(Event events[], int num_events) {
    printf("IP Address\tUsername\tPassword\tTimestamp\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s\t%s\t%s\t%d\n", events[i].ip_address, events[i].username, events[i].password, events[i].timestamp);
    }
}

int main() {
    User users[MAX_USERS];
    Event events[MAX_EVENTS];
    int num_users = 0, num_events = 0;

    // read users from file
    FILE *user_file = fopen("users.txt", "r");
    if (!user_file) {
        perror("Unable to open file: users.txt");
        return 1;
    }
    while (fscanf(user_file, "%s %s %d %d\n", users[num_users].name, users[num_users].password, &users[num_users].login_attempts, &users[num_users].is_locked) == 4) {
        num_users += 1;
    }
    fclose(user_file);

    // read events from file
    FILE *event_file = fopen("events.txt", "r");
    if (!event_file) {
        perror("Unable to open file: events.txt");
        return 1;
    }
    while (fscanf(event_file, "%s %s %s %d\n", events[num_events].ip_address, events[num_events].username, events[num_events].password, &events[num_events].timestamp) == 4) {
        num_events += 1;
    }
    fclose(event_file);

    printf("%d users and %d events loaded\n", num_users, num_events);
    print_events(events, num_events);

    // analyze events and detect potential attacks
    int num_failed_logins = 0, num_successful_logins = 0, num_unique_ip_addresses = 0;
    char unique_ip_addresses[MAX_EVENTS][20];
    for (int i = 0; i < num_events; i++) {
        if (strcasecmp(events[i].username, "root") == 0) {
            printf("Potential privilege escalation attack from IP address %s at timestamp %d\n", events[i].ip_address, events[i].timestamp);
        }
        if (!is_valid_ip_address(events[i].ip_address)) {
            printf("Invalid IP address detected: %s\n", events[i].ip_address);
        } else {
            int is_new_ip_address = 1;
            for (int j = 0; j < num_unique_ip_addresses; j++) {
                if (strcmp(unique_ip_addresses[j], events[i].ip_address) == 0) {
                    is_new_ip_address = 0;
                    break;
                }
            }
            if (is_new_ip_address) {
                strcpy(unique_ip_addresses[num_unique_ip_addresses++], events[i].ip_address);
            }
        }
        int is_successful_login = 0;
        for (int j = 0; j < num_users; j++) {
            if (strcasecmp(users[j].name, events[i].username) == 0 && strcmp(users[j].password, events[i].password) == 0) {
                printf("Login success for user %s from IP address %s at timestamp %d\n", events[i].username, events[i].ip_address, events[i].timestamp);
                is_successful_login = 1;
                break;
            }
        }
        if (!is_successful_login && strcmp(events[i].username, "") != 0) {
            printf("Login failure for user %s from IP address %s at timestamp %d\n", events[i].username, events[i].ip_address, events[i].timestamp);
            num_failed_logins += 1;
            for (int j = 0; j < num_users; j++) {
                if (strcasecmp(users[j].name, events[i].username) == 0) {
                    users[j].login_attempts += 1;
                    if (users[j].login_attempts >= 3) {
                        printf("User %s is locked due to too many login attempts\n", users[j].name);
                        users[j].is_locked = 1;
                    }
                    break;
                }
            }
        }
    }
    printf("%d unique IP addresses detected\n", num_unique_ip_addresses);
    printf("%d failed login attempts detected\n", num_failed_logins);

    // write updated user information to file
    FILE *user_output_file = fopen("users_out.txt", "w");
    if (!user_output_file) {
        perror("Unable to open file: users_out.txt");
        return 1;
    }
    for (int i = 0; i < num_users; i++) {
        fprintf(user_output_file, "%s %s %d %d\n", users[i].name, users[i].password, users[i].login_attempts, users[i].is_locked);
    }
    fclose(user_output_file);

    return 0;
}