//FormAI DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Function to handle interrupts
void handle_sigint(int sig) {
    printf("Caught SIGINT, shutting down...\n");
    exit(0);
}

// Function to check for root privileges
void check_root_privileges() {
    if(geteuid() != 0) {
        printf("Error: Not running with root privileges\n");
        exit(1);
    }
}

// Function to display system information
void display_system_info() {
    printf("System Information:\n");
    printf("Hostname: ");
    system("hostname");
    printf("Memory: ");
    system("free -h");
    printf("Disk Usage: ");
    system("df -h /");
}

// Function to display current logged in users
void display_logged_in_users() {
    printf("Currently Logged In Users:\n");
    system("who");
}

// Function to display network information
void display_network_info() {
    printf("Network Information:\n");
    printf("IP Address: ");
    system("hostname -I");
    printf("Open Ports: ");
    system("netstat -tulpn");
}

int main() {
    signal(SIGINT, handle_sigint);  // Register SIGINT handler

    check_root_privileges();  // Ensure we are running with root privileges

    // Display available options
    printf("Options:\n");
    printf("1. Display System Information\n");
    printf("2. Display Logged In Users\n");
    printf("3. Display Network Information\n");

    int option;
    printf("\nEnter an option (1-3): ");
    scanf("%d", &option);

    switch(option) {
        case 1: display_system_info(); break;
        case 2: display_logged_in_users(); break;
        case 3: display_network_info(); break;
        default: printf("Invalid Option\n");
    }

    return 0;
}