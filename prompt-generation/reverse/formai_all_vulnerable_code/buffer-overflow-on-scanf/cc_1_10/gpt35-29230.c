//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char address[50];
} Person;

void addPerson(Person people[], int* count) {
    char name[50];
    char address[50];

    printf("What's in a name?\n");
    scanf("%s", name);

    printf("Where doth thou live?\n");
    scanf("%s", address);

    Person person = { (*count) + 1, name, address };
    people[*count] = person;
    (*count)++;
}

void searchByName(Person people[], int count) {
    char name[50];

    printf("O, speak again, bright angel!\n");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(name, people[i].name) == 0) {
            printf("What's Montague? It is nor hand, nor foot\n");
            printf("Nor arm, nor face, nor any other part\n");
            printf("Belonging to a man. O, be some other name!\n");
            printf("By any other name would smell as sweet.\n");
            printf("ID: %d - Name: %s - Address: %s\n", people[i].id, people[i].name, people[i].address);
            return;
        }
    }

    printf("O Romeo, Romeo! wherefore art thou Romeo?\n");
    printf("Deny thy father and refuse thy name;\n");
    printf("Or, if thou wilt not, be but sworn my love,\n");
    printf("And I'll no longer be a Capulet.\n");
}

void searchByAddress(Person people[], int count) {
    char address[50];

    printf("What's in a street?\n");
    scanf("%s", address);

    for (int i = 0; i < count; i++) {
        if (strcmp(address, people[i].address) == 0) {
            printf("By heaven, I do love: and it hath taught me to\n");
            printf("night to cut his index finger.\n");
            printf("ID: %d - Name: %s - Address: %s\n", people[i].id, people[i].name, people[i].address);
            return;
        }
    }

    printf("My only love sprung from my only hate!\n");
    printf("Too early seen unknown, and known too late!\n");
}

int main() {
    Person people[50];
    int count = 0;

    while (1) {
        printf("\n-------------------------------------------\n");
        printf("1. Add person\n");
        printf("2. Search by name\n");
        printf("3. Search by address\n");
        printf("4. Exit\n");
        printf("-------------------------------------------\n");
        printf("What's in a name? That which we call a rose\n");
        printf("By any other name would smell as sweet.\n");
        printf("Enter thy choice:\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPerson(people, &count);
                break;
            case 2:
                searchByName(people, count);
                break;
            case 3:
                searchByAddress(people, count);
                break;
            case 4:
                printf("Good night, good night! parting is such\n");
                printf("sweet sorrow, That I shall say good night till\n");
                printf("it be morrow.\n");
                exit(0);
            default:
                printf("A plague o' both your houses!\n");
                break;
        }
    }

    return 0;
}