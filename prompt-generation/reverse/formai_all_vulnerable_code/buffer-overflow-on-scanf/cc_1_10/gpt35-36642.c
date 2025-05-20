//FormAI DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {

    char name[20], job[20], company[20], text[200];
    
    printf("What is your name?\n");
    scanf("%s", name);
    
    printf("What is your profession?\n");
    scanf("%s", job);
    
    printf("Which company do you work for?\n");
    scanf("%s", company);
    
    sprintf(text, "Hello, my name is %s and I am a %s working at %s.", name, job, company);
    printf("%s\n", text);
    
    int text_length = strlen(text) + 1;
    char reversed_text[text_length];
    strcpy(reversed_text, text);
    
    int i, j;
    char temp;
    for (i = 0, j = text_length - 2; i < j; ++i, --j) {
        temp = reversed_text[i];
        reversed_text[i] = reversed_text[j];
        reversed_text[j] = temp;
    }
    
    printf("Reversed text: %s\n", reversed_text);
    
    char renamed_file[20];
    strcpy(renamed_file, name);
    strcat(renamed_file, "_resume.txt");
    
    FILE *fp = fopen(renamed_file, "w");
    if (fp == NULL) {
        printf("Error: Unable to create file\n");
        return 1;
    }
    
    fputs(text, fp);
    fclose(fp);
    
    printf("Your resume has been saved as %s\n", renamed_file);
    
    return 0;
}