//FormAI DATASET v1.0 Category: System administration ; Style: visionary
/*
   ================================================
   Program: Remote Control
   Description: A program that allows you to manage multiple remote systems from a central console.
   Author: [Your Name]
   Date: [Today's Date]
   ================================================
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_HOSTS 10
#define MAX_COMMAND_LENGTH 256

char hosts[MAX_HOSTS][50]; // Array to store hostnames
int total_hosts = 0; // Total number of hosts added

// Function to add a new host to the list
void add_host() {
   char hostname[50];
   printf("Enter hostname to add: ");
   fgets(hostname, 50, stdin);
   hostname[strcspn(hostname, "\n")] = 0; // Remove trailing newline character
   strcpy(hosts[total_hosts], hostname);
   total_hosts++;
   printf("%s added to the list!\n", hostname);
}

// Function to run a command on all hosts in the list
void run_command() {
   char command[MAX_COMMAND_LENGTH];
   printf("Enter command to execute: ");
   fgets(command, MAX_COMMAND_LENGTH, stdin);
   command[strcspn(command, "\n")] = 0;
   for (int i = 0; i < total_hosts; i++) {
      printf("Executing command on %s: %s\n", hosts[i], command);
      // Run command on host using ssh or telnet
      // Code to be added
   }
}

// Main function
int main() {
   printf("Welcome to Remote Control!\n");
   while (1) {
      printf("\nWhat would you like to do?\n");
      printf("1. Add a new host\n");
      printf("2. Run a command on all hosts\n");
      printf("3. Exit\n");
      int choice;
      printf("Enter your choice: ");
      scanf("%d", &choice);
      getchar(); // Remove trailing newline character from input buffer
      switch (choice) {
         case 1:
            if (total_hosts >= MAX_HOSTS) {
               printf("Maximum number of hosts reached!\n");
            } else {
               add_host();
            }
            break;
         case 2:
            if (total_hosts == 0) {
               printf("No hosts added to the list!\n");
            } else {
               run_command();
            }
            break;
         case 3:
            printf("Exiting program...\n");
            exit(0);
         default:
            printf("Invalid choice!\n");
      }
   }
   return 0;
}