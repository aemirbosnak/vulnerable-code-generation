//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define USERNAME_LEN 30

typedef struct {
    char name[USERNAME_LEN];
    int alive; // Status: 1 for alive, 0 for deceased
} User;

void addUser(User users[], int *count, const char *name) {
    if (*count >= MAX_USERS) {
        printf("Alas! The world cannot bear more love. User limit reached!\n");
        return;
    }
    strcpy(users[*count].name, name);
    users[*count].alive = 1;
    (*count)++;
    printf("%s, you are now added to this love story.\n", name);
}

void removeUser(User users[], int *count, const char *name) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(users[i].name, name) == 0 && users[i].alive) {
            users[i].alive = 0; // Mark as deceased
            printf("%s, your light flickers no more. Farewell!\n", name);
            return;
        }
    }
    printf("%s, you are not among the living in this tale.\n", name);
}

void listUsers(const User users[], int count) {
    printf("Here stand the blessed souls:\n");
    for (int i = 0; i < count; i++) {
        if (users[i].alive) {
            printf("- %s\n", users[i].name);
        }
    }
    if (count == 0) {
        printf("There are none to honor in this tragedy.\n");
    }
}

int main() {
    User users[MAX_USERS];
    int userCount = 0;
    int choice;
    char name[USERNAME_LEN];

    while (1) {
        printf("\nWelcome to the tale of users in Verona's UNIX!\n");
        printf("1. Add User (e.g., Romeo)\n");
        printf("2. Remove User (e.g., Juliet)\n");
        printf("3. List Users\n");
        printf("4. Exit the stage\n");
        printf("Please select your fate: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
            case 1:
                printf("Enter the name of the new user: ");
                fgets(name, USERNAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                addUser(users, &userCount, name);
                break;
            case 2:
                printf("Enter the name of the user to remove: ");
                fgets(name, USERNAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                removeUser(users, &userCount, name);
                break;
            case 3:
                listUsers(users, userCount);
                break;
            case 4:
                printf("The tale concludes. Farewell!\n");
                exit(0);
            default:
                printf("Alas! That choice does not exist in this bard's tale!\n");
        }
    }
    return 0;
}