//FormAI DATASET v1.0 Category: Data recovery tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[20];
    char buffer[256];
    int choice, i;
    FILE *file;

    printf("Enter the file name: ");
    scanf("%s", filename);

    printf("What would you like to do?\n");
    printf("1. Read the file\n");
    printf("2. Recover the file\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            file = fopen(filename, "r");
            if(file == NULL) {
                printf("Error opening file.\n");
                exit(1);
            } else {
                while(fgets(buffer, 256, file) != NULL) {
                    printf("%s", buffer);
                }
                fclose(file);
            }
            break;
        case 2:
            file = fopen(filename, "r");
            if(file == NULL) {
                printf("Error opening file.\n");
                exit(1);
            } else {
                fseek(file, 0, SEEK_END);
                long size = ftell(file);
                rewind(file);
                char* file_contents = (char*) malloc((size+1)*sizeof(char));
                fread(file_contents, sizeof(char), size, file);
                fclose(file);

                // Recover deleted data
                for(i = 0; i < size; i++) {
                    if(file_contents[i] == '?') {
                        file_contents[i] = 'a';
                    }
                }

                file = fopen(filename, "w");
                if(file == NULL) {
                    printf("Error opening file.\n");
                    exit(1);
                } else {
                    fwrite(file_contents, sizeof(char), size, file);
                    fclose(file);
                }
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}