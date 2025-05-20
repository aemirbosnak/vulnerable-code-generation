//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int age;
    int steps;
    int calories;
    int heart_rate;
} User;

User users[MAX_SIZE];
int num_users = 0;

void addUser() {
    if (num_users >= MAX_SIZE) {
        printf("Max number of users reached.\n");
        return;
    }

    User newUser;

    printf("Enter name: ");
    scanf("%s", newUser.name);

    printf("Enter age: ");
    scanf("%d", &newUser.age);

    printf("Enter steps: ");
    scanf("%d", &newUser.steps);

    printf("Enter calories burned: ");
    scanf("%d", &newUser.calories);

    printf("Enter heart rate: ");
    scanf("%d", &newUser.heart_rate);

    users[num_users] = newUser;
    num_users++;

    printf("User added successfully.\n");
}

void displayUsers() {
    printf("Name\t\tAge\tSteps\tCalories\tHeart Rate\n");

    for (int i = 0; i < num_users; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", users[i].name, users[i].age, users[i].steps, users[i].calories, users[i].heart_rate);
    }
}

void deleteUser() {
    printf("Enter user name to delete: ");
    char name[50];
    scanf("%s", name);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            for (int j = i; j < num_users - 1; j++) {
                users[j] = users[j + 1];
            }
            num_users--;
            printf("User deleted successfully.\n");
            return;
        }
    }

    printf("User not found.\n");
}

int main() {
    srand(time(NULL));

    int choice;

    do {
        printf("Cyberpunk Fitness Tracker\n");
        printf("1. Add user\n2. Display users\n3. Delete user\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addUser();
            break;
        case 2:
            displayUsers();
            break;
        case 3:
            deleteUser();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}