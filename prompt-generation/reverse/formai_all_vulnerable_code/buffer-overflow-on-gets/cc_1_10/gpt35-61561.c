//FormAI DATASET v1.0 Category: File handling ; Style: curious
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the curious file handling program!\n");

    //create file pointer and open file in write mode
    FILE *myfile = fopen("curiousfile.txt","w");

    //check if file opened successfully
    if(myfile == NULL){
        printf("Unable to open file!\n");
        exit(1);
    }

    printf("Enter a curious sentence to write to the file (max 50 characters): ");
    char sentence[50];
    gets(sentence);

    //write sentence to file
    fputs(sentence, myfile);

    //close file
    fclose(myfile);

    printf("Sentence successfully written to file!\n");

    //open file in read mode
    myfile = fopen("curiousfile.txt","r");

    //check if file opened successfully
    if(myfile == NULL){
        printf("Unable to open file!\n");
        exit(1);
    }

    printf("Reading contents of file: \n");

    //read entire file
    char c;
    while((c = getc(myfile)) != EOF){
        printf("%c",c);
    }

    //close file
    fclose(myfile);

    printf("\nFile reading complete!\n");

    return 0;
}