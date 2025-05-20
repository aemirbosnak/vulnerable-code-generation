//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_SUSPECTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Suspect;

void print_suspect_details(const Suspect* suspect) {
    printf("%s (%d years old)\n", suspect->name, suspect->age);
}

int main() {
    Suspect suspects[MAX_NUM_SUSPECTS];
    char input_name[MAX_NAME_LENGTH];
    int i, age;

    // Populate the suspects array with some data
    strcpy(suspects[0].name, "Professor Moriarty");
    suspects[0].age = 45;

    strcpy(suspects[1].name, "Dr. Watson");
    suspects[1].age = 35;

    strcpy(suspects[2].name, "Mrs. Hudson");
    suspects[2].age = 48;

    // Get a name from the user and find the corresponding suspect
    printf("Enter the name of the suspect you're interested in: ");
    scanf("%s", input_name);

    for (i = 0; i < MAX_NUM_SUSPECTS; i++) {
        if (strcmp(suspects[i].name, input_name) == 0) {
            break;
        }
    }

    if (i >= MAX_NUM_SUSPECTS) {
        printf("Suspect not found.\n");
        return 1;
    }

    // Once we've found the suspect, print their details
    print_suspect_details(&suspects[i]);

    // Ask the user if they want to check another suspect's age
    char check_age[10];
    printf("Do you want to check another suspect's age? (yes/no): ");
    scanf("%s", check_age);

    if (strcasecmp(check_age, "yes") == 0) {
        printf("Enter the name of the suspect: ");
        scanf("%s", input_name);

        for (i = 0; i < MAX_NUM_SUSPECTS; i++) {
            if (strcmp(suspects[i].name, input_name) == 0) {
                printf("The age of %s is: ", input_name);
                scanf("%d", &age);
                suspects[i].age = age;
                break;
            }
        }

        if (i >= MAX_NUM_SUSPECTS) {
            printf("Suspect not found.\n");
            return 1;
        }
    }

    return 0;
}