//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_virus(char *filename)
{
    FILE *file;
    char buffer[1024];
    int virus_count = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(buffer, 1024, file)!= NULL) {
        int i;
        for (i = 0; i < strlen(buffer); i++) {
            if (isalpha(buffer[i]) || isdigit(buffer[i])) {
                continue;
            } else if (buffer[i] == '.' || buffer[i] == '!' || buffer[i] == '?') {
                continue;
            } else {
                virus_count++;
            }
        }
    }

    fclose(file);

    if (virus_count > 0) {
        printf("%s is a virus!\n", filename);
        return 1;
    } else {
        printf("%s is clean.\n", filename);
        return 0;
    }
}

int main()
{
    char filename[1024];

    printf("Enter filename to scan for viruses:\n");
    scanf("%s", filename);

    is_virus(filename);

    return 0;
}