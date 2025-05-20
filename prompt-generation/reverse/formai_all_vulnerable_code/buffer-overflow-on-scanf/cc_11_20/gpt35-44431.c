//FormAI DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 20
#define MAX_LIST_CAPACITY 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} subscriber;

int main() {
    int choice, current_size = 0;
    subscriber mailing_list[MAX_LIST_CAPACITY];

    do {
        printf("\t\tMedieval Mailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. View subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (current_size == MAX_LIST_CAPACITY) {
                    printf("Mailing list is full. No more subscribers can be added.\n");
                } else {
                    printf("Enter subscriber name (max %d characters): ", MAX_NAME_LENGTH - 1);
                    scanf("%s", mailing_list[current_size].name);

                    printf("Enter subscriber email (max %d characters): ", MAX_EMAIL_LENGTH - 1);
                    scanf("%s", mailing_list[current_size].email);

                    current_size++;

                    printf("Subscriber added successfully!\n");
                }
                break;
            case 2:
                if (current_size == 0) {
                    printf("Mailing list is empty. There are no subscribers to remove.\n");
                } else {
                    char search_name[MAX_NAME_LENGTH];
                    printf("Enter name of subscriber to remove: ");
                    scanf("%s", search_name);

                    int found = 0;
                    for (int i = 0; i < current_size; i++) {
                        if (strcmp(mailing_list[i].name, search_name) == 0) {
                            found = 1;
                            for (int j = i; j < current_size - 1; j++) {
                                strcpy(mailing_list[j].name, mailing_list[j+1].name);
                                strcpy(mailing_list[j].email, mailing_list[j+1].email);
                            }
                            current_size--;
                            printf("Subscriber removed successfully!\n");
                        }
                    }

                    if (!found) {
                        printf("Subscriber not found in mailing list.\n");
                    }
                }
                break;
            case 3:
                if (current_size == 0) {
                    printf("Mailing list is empty. There are no subscribers to view.\n");
                } else {
                    printf("Current subscribers: \n");
                    for (int i = 0; i < current_size; i++) {
                        printf("%s\t%s\n", mailing_list[i].name, mailing_list[i].email);
                    }
                }
                break;
            case 4:
                printf("Exiting mailing list manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;

}