//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// function to scan the file for viruses
void antivirus_scanner(char filename[]) {
    char line[MAX],*p;
    FILE *fptr;

    // open the file
    fptr = fopen(filename, "r");

    // check if the file exists or not
    if (!fptr){
        printf("Error: The file \"%s\" does not exist.\n", filename);
        return;
    }

    int line_number = 1;
    int virus_count = 0;

    // read each line of the file
    while (fgets(line, MAX, fptr)) {

        // search for known virus signatures in the line
        if((strstr(line, "virus") != NULL) || (strstr(line, "malware")!=NULL)) {
            virus_count++;

            // print the line number where the virus was found
            printf("\nVirus Found in line %d: \n%s", line_number, line);

            // remove the virus signature from the line
            while((p = strstr(line, "virus"))) {
                memset(p, ' ', strlen("virus"));
            }
            while((p = strstr(line, "malware"))) {
                memset(p, ' ', strlen("malware"));
            }

            // print the line again after removing the virus signature
            printf("\nLine after removing virus signature: \n%s", line);
        }

        line_number++;
    }

    if(virus_count > 0) {
        printf("\n\n *** VIRUS SCAN RESULT *** \n");
        printf("\nNumber of viruses found: %d\n", virus_count);
        printf("\nThe file is infected with viruses.\n");
    } else {
        printf("\n\n *** VIRUS SCAN RESULT *** \n");
        printf("\nNumber of viruses found: %d\n", virus_count);
        printf("\nThe file is virus-free.\n");
    }

    // close the file
    fclose(fptr);
}

int main() {
    char filename[MAX];

    // get the filename from the user
    printf("Enter the filename to be scanned: ");
    scanf("%s", filename);

    // call the antivirus scanner function
    antivirus_scanner(filename);

    return 0;
}