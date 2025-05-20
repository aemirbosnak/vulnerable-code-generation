//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct virus database; // defining a structure for the virus database

struct virus {
    char name[50];
    char signature[25];
    int size;
} viruses[5]; // defining the number of viruses to be scanned

int database_entry() // function to enter virus signature to be stored in the database
{
    int i;
    printf("\nEnter Details of 5 Viruses:\n");
    for(i = 0; i < 5; i++) 
    {
        printf("\nEnter virus name for #%d: ", i+1);
        fgets(viruses[i].name, sizeof(viruses[i].name), stdin);
        printf("Enter virus signature for #%d: ", i+1);
        fgets(viruses[i].signature, sizeof(viruses[i].signature), stdin);
        viruses[i].size = strlen(viruses[i].signature);
    }
    return 0; 
}

int scan_file(char *filename) // function to scan the given file for viruses
{
    FILE *fp;
    char buffer[100];
    char c;
    int match = 0;
    int virus_index = 0;                
    fp = fopen(filename, "r");          
    
    if(fp == NULL)
    {
        printf("Error: Unable to scan, file could not be opened.\n");
        return 1;
    }
    printf("\nScanning the file...\n");
    while(fgets(buffer, sizeof(buffer), fp))
    {
        for(int i = 0; i < strlen(buffer); i++) 
        {
            c = tolower(buffer[i]);
            if(c == viruses[virus_index].signature[match]) 
            {
                match++;
                if(match == viruses[virus_index].size) 
                {
                    printf("\nVirus '%s' found!\n", viruses[virus_index].name);
                    match = 0;
                    virus_index = 0;
                    fclose(fp);
                    return 1;
                }
            }
            else 
            {
                match = 0;
                virus_index++;
                if(virus_index == 5)
                {
                    virus_index = 0;
                }
            }
        }
    }
    fclose(fp); 
    printf("Scanning completed! No virus was found in the file.\n");
    return 0; 
}

int main()
{
    int choice;
    char filename[20];
    printf("Welcome to the C Antivirus Scanner Program!\n");
    printf("1. Add Virus Signatures to the Database\n2. Scan a File\n3. Quit\n");
    do {
        printf("\nEnter the choice(1/2/3): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                database_entry(); 
                break;
            case 2: 
                printf("\nEnter the name of the file to scan: ");
                scanf("%s", filename); 
                scan_file(filename); 
                break;
            case 3: 
                printf("\nExiting from Program..."); 
                break;
            default: 
                printf("\nInvalid Choice, Please Try Again!"); 
                break;
        }
    } while(choice != 3);

    return 0;
}