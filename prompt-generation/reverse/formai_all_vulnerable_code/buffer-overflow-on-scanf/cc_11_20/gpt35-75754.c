//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include<stdio.h>

int main(){
    // Welcome message
    printf("Welcome to C Antivirus Scanner!\n");

    // Getting input file name
    char filename[50];
    printf("Please enter the name of the file you want to scan: ");
    scanf("%s", &filename);

    // Opening file
    FILE *fp;
    fp = fopen(filename, "r");

    // Checking if file exists
    if(fp == NULL){
        printf("File doesn't exist.\n");
        return 0;
    }

    // Scanning file
    char c;
    int virusCount = 0;
    while((c = fgetc(fp)) != EOF){
        if(c == 'v' || c == 'V'){
            char nextChar = fgetc(fp);
            if(nextChar == 'i' || nextChar == 'I'){
                nextChar = fgetc(fp);
                if(nextChar == 'r' || nextChar == 'R'){
                    nextChar = fgetc(fp);
                    if(nextChar == 'u' || nextChar == 'U'){
                        nextChar = fgetc(fp);
                        if(nextChar == 's' || nextChar == 'S'){
                            virusCount++;
                        }
                    }
                }
            }
        }
    }

    // Closing file
    fclose(fp);

    if(virusCount > 0){
        printf("File is infected with %d viruses.\n", virusCount);
    }else{
        printf("File is clean.\n");
    }
    
    return 0;
}