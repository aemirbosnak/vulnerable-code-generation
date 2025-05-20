//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 50
#define MAX_RECORDS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
} Record;

int main() {
    Record database[MAX_RECORDS];
    int num_records = 0;

    while (1) {
        printf("\n1. Add record\n");
        printf("2. Search record by name\n");
        printf("3. Search record by phone\n");
        printf("4. Search record by email\n");
        printf("5. Exit\n");

        int choice;
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_records == MAX_RECORDS) {
                    printf("\nDatabase is full!\n");
                    break;
                }

                Record r;
                printf("\nEnter name: ");
                scanf("%s", r.name);
                printf("Enter phone: ");
                scanf("%s", r.phone);
                printf("Enter email: ");
                scanf("%s", r.email);

                database[num_records] = r;
                num_records++;

                printf("\nRecord added successfully!\n");
                break;
            }

            case 2: {
                char name[MAX_NAME_LEN];
                printf("\nEnter name to search: ");
                scanf("%s", name);

                int found = 0;
                for (int i = 0; i < num_records; i++) {
                    if (strcmp(database[i].name, name) == 0) {
                        printf("\nRecord found!\n");
                        printf("Name: %s\n", database[i].name);
                        printf("Phone: %s\n", database[i].phone);
                        printf("Email: %s\n", database[i].email);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\nRecord not found!\n");
                }

                break;
            }

            case 3: {
                char phone[MAX_PHONE_LEN];
                printf("\nEnter phone to search: ");
                scanf("%s", phone);

                int found = 0;
                for (int i = 0; i < num_records; i++) {
                    if (strcmp(database[i].phone, phone) == 0) {
                        printf("\nRecord found!\n");
                        printf("Name: %s\n", database[i].name);
                        printf("Phone: %s\n", database[i].phone);
                        printf("Email: %s\n", database[i].email);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\nRecord not found!\n");
                }

                break;
            }

            case 4: {
                char email[MAX_EMAIL_LEN];
                printf("\nEnter email to search: ");
                scanf("%s", email);

                int found = 0;
                for (int i = 0; i < num_records; i++) {
                    if (strcmp(database[i].email, email) == 0) {
                        printf("\nRecord found!\n");
                        printf("Name: %s\n", database[i].name);
                        printf("Phone: %s\n", database[i].phone);
                        printf("Email: %s\n", database[i].email);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\nRecord not found!\n");
                }

                break;
            }

            case 5: {
                exit(0);
                break;
            }

            default: {
                printf("\nInvalid choice!\n");
                break;
            }
        }
    }

    return 0;
}