//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Person;

int is_valid_email(const char* email) {
    int at_pos = -1, dot_pos = -1;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            at_pos = i;
        }
        if (email[i] == '.') {
            dot_pos = i;
        }

        if (at_pos != -1 && dot_pos != -1 && i > at_pos) {
            break;
        }

        if (i > MAX_EMAIL_LEN - 1) {
            return 0;
        }

        if (!isalnum(email[i]) && email[i] != '.' && email[i] != '@') {
            return 0;
        }
    }

    return at_pos != -1 && dot_pos != -1 && dot_pos > at_pos;
}

int main() {
    Person people[100];
    int num_people = 0;

    while (num_people < 100) {
        printf("Enter a name: ");
        scanf("%s", people[num_people].name);
        getchar(); // consume newline

        printf("Enter an email address: ");
        char email[MAX_EMAIL_LEN];
        scanf("%s", email);

        if (is_valid_email(email)) {
            strcpy(people[num_people].email, email);
            num_people++;
        } else {
            printf("Invalid email address. Please try again.\n");
        }
    }

    printf("\nList of valid emails:\n");
    for (int i = 0; i < num_people; i++) {
        if (is_valid_email(people[i].email)) {
            printf("%s (%s)\n", people[i].name, people[i].email);
        }
    }

    return 0;
}