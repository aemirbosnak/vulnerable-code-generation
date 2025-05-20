//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program extracts metadata from a file in C */
/* The metadata is stored in the file as a series of key value pairs */

int main() {

    //define variables
    FILE *fp;
    char filename[50];
    char key[50], value[50];
    char ch;
    int i=0;

    //ask user for filename and open the file
    printf("Enter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");

    //check if file is open
    if (fp == NULL) {
        printf("Error opening file.");
        return 0;
    }

    //loop through each character in file
    while((ch=fgetc(fp))!=EOF){

        //if character is a '$', then a key value pair has started
        if(ch == '$'){
            i=0;
            //loop through until '=' is found (this is the end of the key)
            while((ch=fgetc(fp))!='='){
                key[i] = ch;
                i++;
            }
            //add null terminator to key
            key[i] = '\0';
            i=0;
            //loop through until ':' is found (this is the end of the value)
            while((ch=fgetc(fp))!=':'){
                value[i] = ch;
                i++;
            }
            //add null terminator to value
            value[i] = '\0';
            //print the key value pair
            printf("%s: %s\n", key, value);
        }
    }

    //close the file and exit
    fclose(fp);
    return 0;
}