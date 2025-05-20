//FormAI DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000

void write_entry(FILE *fp){ //writes a new entry to the diary
    char entry[MAX_LENGTH];
    printf("Write your entry:\n");
    fgets(entry, MAX_LENGTH, stdin);
    fprintf(fp, "%s\n", entry);
}

void print_entry(FILE *fp){ //prints all entries in the diary
    printf("--------Entries--------\n");
    char c = fgetc(fp);
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(fp);
    }
    printf("------------------------\n");
}

int main(){
    char filename[] = "diary.txt"; //name of the diary file
    FILE *fp; //file pointer
    char c;
    fp = fopen(filename, "a+"); //opens the diary file in append mode, creates the file if it doesn't exist
    if (fp == NULL){ //checks if the file could be opened
        printf("Could not open file\n");
        return 1;
    }
    printf("Welcome to your digital diary!\n");
    printf("Type 'w' to write a new entry, 'p' to print all entries and 'q' to quit.\n");
    while(1){
        scanf("%c", &c);
        switch(c){
            case 'w':
                write_entry(fp);
                break;
            case 'p':
                print_entry(fp);
                break;
            case 'q':
                printf("Goodbye!\n");
                fclose(fp); //closes the file
                return 0;
            default:
                printf("Unknown command, try again.\n");
        }
    }
    return 0;
}