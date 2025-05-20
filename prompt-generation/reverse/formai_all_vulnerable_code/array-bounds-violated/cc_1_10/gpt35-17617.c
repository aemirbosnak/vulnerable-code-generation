//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Structure to store tag name and attributes
struct tag {
    char name[30];
    char attributes[100];
};

//Function to parse the XML file
void parseXML(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Unable to open XML file!\n");
        exit(1);
    }

    char buffer[100];
    int i=0, j;
    struct tag t;
    
    int tag_count = 0;
    
    printf("XML Content:\n");
    printf("--------------------------------------\n");

    //Loop through each character of the file
    while( (buffer[i] = fgetc(fp)) != EOF ) {
        
        //If we encounter the start of a new tag
        if(buffer[i] == '<') {
            i++;
            j = 0;
            
            //Loop through until we reach the end of the tag name
            while(buffer[i] != ' ' && buffer[i] != '>') {
                t.name[j++] = buffer[i++];
            }
            t.name[j] = '\0';
            
            //If the tag has attributes, store them
            if(buffer[i] == ' ') {
                j = 0;
                i++;

                //Loop through each attribute until we reach the end of the tag
                while(buffer[i] != '>') {
                    t.attributes[j++] = buffer[i++];
                }
                t.attributes[j] = '\0';
            }
            
            tag_count++;
            printf("\n%d. Tag: %s", tag_count, t.name);
            if(strlen(t.attributes) > 0) {
                printf("\n   Attributes: %s", t.attributes);
            }
        }
        
        //Print the content of the tag
        if(buffer[i] != '<' && buffer[i] != '>') {
            printf("%c", buffer[i]);
        }
        i++;
    }
    
    printf("\n--------------------------------------\n");
    printf("Total Tags: %d\n", tag_count);

    fclose(fp);
}

int main() {
    parseXML("example.xml");
    return 0;
}