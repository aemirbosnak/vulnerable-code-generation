//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int age;
    char rating[20];
} User;

int main() {
    int n, i;
    User users[5];
    char choice;
    char menu[] = "1. Add a user \n2. View all users \n3. Search for a user \n4. Exit \n";

    printf("Welcome to the Movie Rating System!\n");
    printf("%s\n", menu);

    do {
        printf("Enter your choice: ");
        scanf("%d", &n);
        switch (n) {
            case 1: {
                printf("Enter the user's name: ");
                scanf("%s", users[i].name);
                printf("Enter the user's age: ");
                scanf("%d", &users[i].age);
                printf("Enter the user's rating: ");
                scanf("%s", users[i].rating);
                break;
            }
            case 2: {
                printf("All users:\n");
                for (i = 0; i < 5; i++) {
                    printf("%s - %d - %s\n", users[i].name, users[i].age, users[i].rating);
                }
                break;
            }
            case 3: {
                printf("Enter the user's name: ");
                scanf("%s", users[i].name);
                for (i = 0; i < 5; i++) {
                    if (strcmp(users[i].name, users[i].name) == 0) {
                        printf("User found.\n");
                        printf("Name: %s\n", users[i].name);
                        printf("Age: %d\n", users[i].age);
                        printf("Rating: %s\n", users[i].rating);
                        break;
                    }
                }
                break;
            }
            case 4: {
                printf("Thank you for using the Movie Rating System!\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    } while (n!= 4);

    return 0;
}