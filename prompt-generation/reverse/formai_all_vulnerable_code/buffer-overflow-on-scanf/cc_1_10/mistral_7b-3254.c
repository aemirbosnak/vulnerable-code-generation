//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char message[MAX_LINE_LENGTH];
} Letter;

int main() {
    FILE *file;
    char filename[MAX_NAME_LENGTH];
    Letter letters[2];

    strcpy(letters[0].name, "Romeo");
    strcpy(letters[1].name, "Juliet");

    file = fopen("love_letters.txt", "w");

    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return 1;
    }

    for (int i = 0; i < 2; i++) {
        fprintf(file, "%s:\n", letters[i].name);
        printf("%s, write me a letter:\n", letters[i].name);
        scanf("%s", letters[i].message);
        fputs(letters[i].message, file);
        fputs("\n", file);
    }

    fclose(file);
    printf("Love letters have been written.\n");

    file = fopen("love_letters.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open file for reading.\n");
        return 1;
    }

    printf("\n%s's letter:\n", letters[0].name);
    fgets(letters[0].message, MAX_LINE_LENGTH, file);
    printf("%s", letters[0].message);

    printf("\n%s's letter:\n", letters[1].name);
    fgets(letters[1].message, MAX_LINE_LENGTH, file);
    printf("%s", letters[1].message);

    fclose(file);

    return 0;
}