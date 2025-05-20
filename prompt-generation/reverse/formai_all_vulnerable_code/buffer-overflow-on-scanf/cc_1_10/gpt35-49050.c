//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
//Shape-shifting CSV reader example program

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data { //creating structure to hold CSV data
    char name[50];
    int age;
    char city[50];
}person;

int main() {
    FILE* filepointer; //pointer to file object
    char filename[20], line[100]; //declaring variables to hold user input and CSV line data
    printf("Enter filename to open: ");
    scanf("%s", filename); //taking user input for filename
    
    //iterating over filename to change case of first letter randomly
    for(int i=0; i<strlen(filename); i++) {
        if(filename[i]>='a' && filename[i]<='z') { //if lowercase letter
            if(rand()%2 == 0) { //randomly decide to change case
                filename[i] = filename[i] - 32; //change case to uppercase
            }
        }
    }
    printf("Opening file %s...\n", filename);
    filepointer = fopen(filename, "r"); //opening file in read mode
    
    if(filepointer == NULL) { //if file not found or unable to open
        printf("Error: File not found or unable to open.\n");
        exit(0);
    }
    
    while(fgets(line, 100, filepointer)) { //reading CSV lines
        char* token = strtok(line, ","); //splitting CSV line with delimiter
        
        strcpy(person.name, token); //parsing CSV data to structure
        token = strtok(NULL, ",");
        person.age = atoi(token);
        token = strtok(NULL, ",");
        strcpy(person.city, token);
        
        printf("Name: %s, Age: %d, City: %s\n", person.name, person.age, person.city);
    }
    fclose(filepointer); //closing file
    
    //printing random shape-shifting code block
    printf("\n/*---------------------------------------------*/\n");
    switch(rand()%3) { //randomly select one of three code blocks
        case 0: printf("if(x>x+5) { x=x-5; } else { x=x+5; }\n");
        case 1: printf("#define square(a) ((a)*(a))\n");
        case 2: printf("for(int i=0; i<x; i++) { printf(\"%d \", i); }\n");
    }
    printf("/*---------------------------------------------*/\n");
    
    return 0;
}