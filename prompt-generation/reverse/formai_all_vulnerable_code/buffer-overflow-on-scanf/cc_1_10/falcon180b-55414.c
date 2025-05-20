//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_COUNT 100
#define VIRUS_NAME_LENGTH 50
#define FILE_NAME_LENGTH 100

struct virus {
    char name[VIRUS_NAME_LENGTH];
    char file_name[FILE_NAME_LENGTH];
};

void add_virus(struct virus *viruses, int count, char *name, char *file_name) {
    if (count >= MAX_VIRUS_COUNT) {
        printf("Error: Maximum virus count reached.\n");
        return;
    }
    strcpy(viruses[count].name, name);
    strcpy(viruses[count].file_name, file_name);
    count++;
}

int main() {
    struct virus viruses[MAX_VIRUS_COUNT];
    int count = 0;
    char input[100];

    printf("Enter virus name and file name (separated by space):\n");
    scanf("%s", input);

    char *name = strtok(input, " ");
    char *file_name = strtok(NULL, " ");

    add_virus(viruses, count, name, file_name);

    printf("Enter more viruses? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        printf("Enter virus name and file name (separated by space):\n");
        scanf("%s", input);

        name = strtok(input, " ");
        file_name = strtok(NULL, " ");

        add_virus(viruses, count, name, file_name);

        printf("Enter more viruses? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Viruses found:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", viruses[i].name, viruses[i].file_name);
    }

    return 0;
}