//FormAI DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct Entry {
    char name[50];
    char phone[20];
    char email[50];
};

int main() {
    struct Entry directory[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to your Cyberphone Book!\n");
    printf("Please select an option:\n\t1. Add an entry\n\t2. Search for an entry\n\t3. Display all entries\n\t4. Exit\n");

    int option = 0;
    char buffer[100];

    while (option != 4) {
        printf("\nEnter your choice (1-4): ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &option);

        switch (option) {
            case 1:
                if (num_entries == MAX_ENTRIES) {
                    printf("\nDirectory is full, cannot add another entry.\n");
                    break;
                }

                printf("\nEnter name: ");
                fgets(directory[num_entries].name, sizeof(directory[num_entries].name), stdin);
                directory[num_entries].name[strcspn(directory[num_entries].name, "\n")] = '\0';

                printf("Enter phone number: ");
                fgets(directory[num_entries].phone, sizeof(directory[num_entries].phone), stdin);
                directory[num_entries].phone[strcspn(directory[num_entries].phone, "\n")] = '\0';

                printf("Enter email address: ");
                fgets(directory[num_entries].email, sizeof(directory[num_entries].email), stdin);
                directory[num_entries].email[strcspn(directory[num_entries].email, "\n")] = '\0';

                printf("\nEntry added!\n");
                num_entries++;
                break;

            case 2:
                printf("\nEnter name to search for: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';

                for (int i = 0; i < num_entries; i++) {
                    if (strcmp(buffer, directory[i].name) == 0) {
                        printf("\nName: %s\nPhone: %s\nEmail: %s\n", directory[i].name, directory[i].phone, directory[i].email);
                        break;
                    }
                }

                printf("\nEntry not found.\n");
                break;

            case 3:
                printf("\nAll entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("\nName: %s\nPhone: %s\nEmail: %s\n", directory[i].name, directory[i].phone, directory[i].email);
                }
                break;

            case 4:
                printf("\nThank you for using Cyberphone Book.\n");
                break;

            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }
    }

    return 0;
}