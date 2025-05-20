//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: happy
#include <stdio.h>
#include <stdbool.h>

/* This is our happy C Antivirus scanner program! */
int main(void) {
    printf("Hello! Welcome to our C Antivirus scanner program!\n");
    printf("We promise to keep your computer safe and happy :)\n");
    
    /* Get the name of the file to scan from the user */
    char filename[100];
    printf("Please enter the name of the file to scan: ");
    scanf("%s", filename);
    
    /* Open the file for scanning */
    FILE *file;
    file = fopen(filename, "r");
    
    /* Check if the file exists */
    if (file == NULL) {
        printf("Sorry, the file %s does not exist.\n", filename);
    } else {
        printf("Scanning file %s...\n", filename);
        
        /* Read the file and check for any suspicious code */
        char c;
        bool found_virus = false;
        int line_num = 1;
        while ((c = fgetc(file)) != EOF) {
            if (c == 'v' && fgetc(file) == 'i' && fgetc(file) == 'r' && fgetc(file) == 'u' && fgetc(file) == 's') {
                printf("Virus found on line %d!\n", line_num);
                found_virus = true;
            }
            if (c == '\n') {
                line_num++;
            }
        }
        
        /* Close the file */
        fclose(file);
        
        /* React accordingly to the scan results */
        if (found_virus) {
            printf("Oh no! We found a virus in file %s.\n", filename);
            printf("Please delete the file and do not run any suspicious programs.\n");
        } else {
            printf("Good news! File %s did not contain any viruses.\n", filename);
        }
    }
    
    printf("Thank you for using our C Antivirus scanner program! Have a nice day :)\n");
    return 0;
}