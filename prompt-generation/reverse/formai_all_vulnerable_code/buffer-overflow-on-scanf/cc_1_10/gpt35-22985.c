//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // declare variables
    char filename[50];
    FILE *fp;
    int ch, i = 0, virus = 0;
    char buffer[9] = "virus123";
    
    // get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // open file
    fp = fopen(filename, "r");

    // check if file exists
    if (!fp) {
        printf("Error! File not found.");
        exit(1);
    }

    // read each character in file
    while ((ch = fgetc(fp)) != EOF) {

        // check for virus
        if (ch == buffer[i]) {
            i++;
            if (i == 8) {
                virus = 1;
                break;
            }
        }
        else {
            i = 0;
        }
    }

    // close file
    fclose(fp);

    // print result
    if (virus) {
        printf("File contains a virus!");
    }
    else {
        printf("File is clean.");
    }

    return 0;
}