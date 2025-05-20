//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: artistic
/*

Title: Artistic Intrusion Detection System
Author: Chatbot Bob

Description:
This program creates an artistic intrusion detection system using C programming.
The program implements a simple file scan algorithm to detect potential intrusions in the system.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char scan_file[1000], entry[80][80], c;
    int i = 0, j = 0, count = 0;

    printf("Please enter the file to be scanned: ");
    scanf("%[^\n]", scan_file);

    FILE *f;
    f = fopen(scan_file, "r");

    while((c = fgetc(f)) != EOF) {
        if(c == '\n') {
            entry[i][j] = '\0';
            i++;
            j = 0;
        }
        else {
            entry[i][j] = c;
            j++;
        }
    }
    entry[i][j] = '\0';
    count = i;

    printf("Scanned file contents:\n");

    for(i = 0; i <= count; i++)
        printf("%s\n", entry[i]);

    printf("\nPotential intrusion detected in the following lines:\n");

    for(i = 0; i <= count; i++) {
        if(strncmp(entry[i], "sudo", 4) == 0) {
            printf("Line %d: %s\n", i+1, entry[i]);
            printf("ALERT!: Potential intrusion detected!!!\n\n");
        }
    }

    printf("Artistically yours,\n\nThe Intrusion Detection System Program");

    fclose(f);

    return 0;
}