//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to store XML tags */
typedef struct {
    char tag[50];
    char value[100];
} XMLTag;

/* Function to parse the XML file */
void parseXML(char *fileName) {
    FILE *fp;
    char ch;
    int i = 0, j = 0, numOfTags = 0;
    XMLTag tags[100];   // Array to store XML Tags
    
    fp = fopen(fileName, "r");  // Open the XML file in read mode
    
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", fileName);
        exit(1);
    }
    
    /* Loop through the file character by character */
    while ((ch = getc(fp)) != EOF) {
        
        /* Check for start tag '<' */
        if (ch == '<') {
            
            i = 0;  // Reset the index
            
            /* Loop through the characters until the end of the tag */
            while ((ch = getc(fp)) != '>') {
                
                /* Store the characters of the tag in the structure */
                tags[numOfTags].tag[i] = ch;
                i++;
            }
            
            tags[numOfTags].tag[i] = '\0';  // Add null character to the end of the tag
            
            numOfTags++;  // Increment the number of tags
            
        } else if (ch == '>') {   // Skip the closing tag
            
            continue;
            
        } else {   // Store the value of the tag
            
            j = 0;  // Reset the index
            
            /* Loop through the characters until the end of the value */
            while ((ch = getc(fp)) != '<') {
                
                /* Store the characters of the value in the structure */
                tags[numOfTags-1].value[j] = ch;
                j++;
            }
            
            tags[numOfTags-1].value[j] = '\0';  // Add null character to the end of the value
        }
    }
    
    fclose(fp);  // Close the file
    
    /* Print the tags and their values */
    for (i = 0; i < numOfTags; i++) {
        printf("%s: %s\n", tags[i].tag, tags[i].value);
    }
}

int main() {
    char fileName[50];
    
    printf("Enter the name of the XML file: ");
    fgets(fileName, 50, stdin);
    fileName[strcspn(fileName, "\n")] = '\0';   // Remove the newline character from the input string
    
    printf("Parsing %s...\n", fileName);
    
    parseXML(fileName);  // Call the function to parse the XML file
    
    return 0;
}