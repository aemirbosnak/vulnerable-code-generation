//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORY_LENGTH 1000
#define NUM_CONSPIRACIES 10
#define NUM_ELEMENTS 5

const char* elements[NUM_ELEMENTS] = { "The moon is made of green cheese", "The Illuminati", "Lizard people", "Area 51", "The flat Earth" };
const char* causes[NUM_ELEMENTS] = { "is controlled by", "conspires to hide", "infiltrated by", "is a cover for", "believed to be" };
const char* effects[NUM_ELEMENTS] = { "world domination", "the truth about aliens", "mind control of the masses", "advanced technology", "the end of humanity" };
const char* triggers[NUM_ELEMENTS] = { "an ancient prophecy", "a leaked document", "a strange symbol", "a mysterious event", "a conspiracy theorist's wild claim" };

void generateTheory(char theory[MAX_THEORY_LENGTH]) {
    int i, j, k;
    char temp[100];

    srand(time(NULL));

    strcpy(theory, "");

    i = rand() % NUM_CONSPIRACIES;
    strcat(theory, elements[i]);
    strcat(theory, " ");

    j = rand() % NUM_ELEMENTS;
    strcat(theory, causes[j]);
    strcat(theory, " ");

    i = rand() % NUM_ELEMENTS;
    strcpy(temp, elements[i]);
    strcat(theory, temp);
    strcat(theory, " ");

    j = rand() % NUM_ELEMENTS;
    strcpy(temp, causes[j]);
    strcat(theory, temp);
    strcat(theory, " ");

    strcat(theory, effects[rand() % NUM_ELEMENTS]);
    strcat(theory, " because ");

    j = rand() % NUM_ELEMENTS;
    strcpy(temp, triggers[j]);
    strcat(theory, temp);
    strcat(theory, ".");
}

int main() {
    char theory[MAX_THEORY_LENGTH];

    printf("Generate a random conspiracy theory:\n");
    generateTheory(theory);
    printf("%s\n", theory);

    return 0;
}