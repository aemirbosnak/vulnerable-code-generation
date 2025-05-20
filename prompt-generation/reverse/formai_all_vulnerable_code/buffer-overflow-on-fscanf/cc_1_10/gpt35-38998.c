//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// Welcome message to the user
void welcomeMessage(){
    printf("Welcome to the C Word Frequency Counter!\n");
}

// Function to get user input for text file
FILE *getInputFile(){
    char filename[50];
    FILE *fp;

    printf("\nEnter the name of the text file (with .txt extension): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("\nError opening file. Please check if the file name is correct.\n");
        exit(1);
    }

    return fp;
}

// Function to calculate the frequency of each word
// and store it in a linked list
struct node{
    char *word;
    int count;
    struct node *next;
} *head = NULL;

void insertWord(char *word){
    struct node *temp = head;

    while(temp != NULL){
        if(strcmp(temp->word, word) == 0){
            temp->count += 1;
            return;
        }
        temp = temp->next;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->word = word;
    new_node->count = 1;
    new_node->next = head;
    head = new_node;
}

void calculateWordFrequency(FILE *fp){
    char word[50];

    while(fscanf(fp, "%s", word) != EOF){
        for(int i = 0; word[i]; i++){
            word[i] = tolower(word[i]);
        }

        char *new_word = (char *)malloc(strlen(word) + 1);
        strcpy(new_word, word);

        if(isalpha(new_word[0])){
            insertWord(new_word);
        }
    }
}

// Function to display the word frequencies in descending order
void displayWordFrequency(){
    struct node *temp = head;

    printf("\nWord\tFrequency\n");
    printf("------------------\n");

    while(temp != NULL){
        printf("%s\t%d\n", temp->word, temp->count);
        temp = temp->next;
    }
}

int main(){
    welcomeMessage();

    FILE *fp = getInputFile();

    calculateWordFrequency(fp);

    displayWordFrequency();

    fclose(fp);

    return 0;
}