//Falcon-180B DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[50];
    char line[100];
    int count = 0;
    int vowel_count = 0;

    // prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // open file in read mode
    file = fopen(filename, "r");

    // check if file is opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // read file line by line
    while (fgets(line, 100, file)!= NULL) {
        count++;

        // remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // convert line to lowercase
        for (int i = 0; line[i]!= '\0'; i++) {
            line[i] = tolower(line[i]);
        }

        // count vowels in line
        for (int i = 0; line[i]!= '\0'; i++) {
            if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u') {
                vowel_count++;
            }
        }

        // display line with vowel count
        printf("%d: %s (vowel count: %d)\n", count, line, vowel_count);
        vowel_count = 0;
    }

    // close file
    fclose(file);

    return 0;
}