//FormAI DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to hold subscriber information
typedef struct {
    char* name;
    char* email;
    int age;
    int subscribed;
} Subscriber;

int main() {
    // Declare variables
    char input[20];
    int num_subscribers = 0;
    
    // Allocate memory for subscribers
    Subscriber* subscribers = malloc(num_subscribers * sizeof(Subscriber));

    // Main program loop
    while (1) {
        printf("Enter a command (add/remove/list/update/exit): ");
        scanf("%s", input);

        // Add subscriber command
        if (strcmp(input, "add") == 0) {
            printf("Enter subscriber name: ");
            char* name = malloc(20 * sizeof(char));
            scanf("%s", name);

            printf("Enter subscriber email: ");
            char* email = malloc(50 * sizeof(char));
            scanf("%s", email);

            printf("Enter subscriber age: ");
            int age;
            scanf("%d", &age);

            // Add new subscriber to list
            num_subscribers++;
            subscribers = realloc(subscribers, num_subscribers * sizeof(Subscriber));
            subscribers[num_subscribers-1].name = name;
            subscribers[num_subscribers-1].email = email;
            subscribers[num_subscribers-1].age = age;
            subscribers[num_subscribers-1].subscribed = 1;

            printf("Subscriber added.\n");
        }

        // Remove subscriber command
        else if (strcmp(input, "remove") == 0) {
            printf("Enter subscriber email to remove: ");
            char* email = malloc(50 * sizeof(char));
            scanf("%s", email);

            // Find matching subscriber by email and remove from list
            int i;
            for (i = 0; i < num_subscribers; i++) {
                if (strcmp(subscribers[i].email, email) == 0) {
                    free(subscribers[i].name);
                    free(subscribers[i].email);
                    num_subscribers--;
                    memmove(&subscribers[i], &subscribers[i+1], (num_subscribers-i) * sizeof(Subscriber));
                    subscribers = realloc(subscribers, num_subscribers * sizeof(Subscriber));
                    printf("Subscriber removed.\n");
                    break;
                }
            }
            if (i == num_subscribers) {
                printf("Subscriber with email %s not found.\n", email);
            }
        }

        // List subscribers command
        else if (strcmp(input, "list") == 0) {
            printf("Subscribers:\n");
            int i;
            for (i = 0; i < num_subscribers; i++) {
                printf("%s, %s, %d\n", subscribers[i].name, subscribers[i].email, subscribers[i].age);
            }
        }

        // Update subscriber command
        else if (strcmp(input, "update") == 0) {
            printf("Enter subscriber email to update: ");
            char* email = malloc(50 * sizeof(char));
            scanf("%s", email);

            // Find matching subscriber by email and update information
            int i;
            for (i = 0; i < num_subscribers; i++) {
                if (strcmp(subscribers[i].email, email) == 0) {
                    printf("Enter new name (leave blank to not change): ");
                    char* name = malloc(20 * sizeof(char));
                    scanf("%s", name);
                    if (strcmp(name, "") != 0) {
                        free(subscribers[i].name);
                        subscribers[i].name = name;
                    }

                    printf("Enter new email (leave blank to not change): ");
                    char* email = malloc(50 * sizeof(char));
                    scanf("%s", email);
                    if (strcmp(email, "") != 0) {
                        free(subscribers[i].email);
                        subscribers[i].email = email;
                    }

                    printf("Enter new age (leave blank to not change): ");
                    char age_input[10];
                    scanf("%s", age_input);
                    if (strcmp(age_input, "") != 0) {
                        int age = atoi(age_input);
                        subscribers[i].age = age;
                    }

                    printf("Subscriber updated.\n");
                    break;
                }
            }
            if (i == num_subscribers) {
                printf("Subscriber with email %s not found.\n", email);
            }
        }

        // Exit program command
        else if (strcmp(input, "exit") == 0) {
            // Free memory and exit program
            int i;
            for (i = 0; i < num_subscribers; i++) {
                free(subscribers[i].name);
                free(subscribers[i].email);
            }
            free(subscribers);
            printf("Goodbye!\n");
            return 0;
        }

        // Invalid command
        else {
            printf("Invalid command.\n");
        }
    }
}