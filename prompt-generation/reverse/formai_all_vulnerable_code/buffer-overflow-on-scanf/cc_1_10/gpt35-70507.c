//FormAI DATASET v1.0 Category: HTML beautifier ; Style: relaxed
#include <stdio.h>

// function to count the number of spaces before the word
int countSpaces(char *line, int index) {
    int count = 0;
    while (line[index] == ' ') {
        count++;
        index++;
    }
    return count;
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter the name of the HTML file (including .html extension): ");
    scanf("%s", filename);

    // open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    } 

    // read each line of the file
    char line[1000];
    while (fgets(line, 1000, fp)) {
        int i = 0;
        while (line[i] != '\0') {
            int nSpaces = countSpaces(line, i);
            if (line[i] == '<') {
                // indent tags by adding appropriate number of spaces
                printf("%*s%c", nSpaces, "", line[i]);
            } else if (line[i] == '>') {
                // do not indent closing tags
                printf("%c\n", line[i]);
            } else {
                // print other characters without adding spaces
                printf("%c", line[i]);
            }
            i++;
        }
    }

    // close the file
    fclose(fp);

    return 0;
}