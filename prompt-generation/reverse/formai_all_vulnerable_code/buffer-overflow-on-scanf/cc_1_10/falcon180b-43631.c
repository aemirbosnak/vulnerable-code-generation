//Falcon-180B DATASET v1.0 Category: File handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];
    char choice;

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    do {
        printf("Enter choice:\n");
        printf("1. Read file\n");
        printf("2. Write to file\n");
        printf("3. Append to file\n");
        printf("4. Close file\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                fseek(file, 0, SEEK_SET);
                while (fscanf(file, "%s", filename)!= EOF) {
                    printf("%s\n", filename);
                }
                break;
            case '2':
                printf("Enter text to write: ");
                fseek(file, 0, SEEK_SET);
                fprintf(file, "%s", "This text was written to the file.\n");
                break;
            case '3':
                printf("Enter text to append: ");
                fseek(file, 0, SEEK_END);
                fprintf(file, "%s", "This text was appended to the file.\n");
                break;
            case '4':
                fclose(file);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}