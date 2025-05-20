//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an array to store the alien language words
char alienWords[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

// Function to translate the alien language word to English
char* translateAlienWord(char* word) {
    if (strcmp(word, "A") == 0) {
        return "Peaceful";
    } else if (strcmp(word, "B") == 0) {
        return "Harmony";
    } else if (strcmp(word, "C") == 0) {
        return "Unity";
    } else if (strcmp(word, "D") == 0) {
        return "Love";
    } else if (strcmp(word, "E") == 0) {
        return "Understanding";
    } else if (strcmp(word, "F") == 0) {
        return "Respect";
    } else if (strcmp(word, "G") == 0) {
        return "Friendship";
    } else if (strcmp(word, "H") == 0) {
        return "Tolerance";
    } else if (strcmp(word, "I") == 0) {
        return "Compassion";
    } else if (strcmp(word, "J") == 0) {
        return "Generosity";
    } else if (strcmp(word, "K") == 0) {
        return "Humility";
    } else if (strcmp(word, "L") == 0) {
        return "Patience";
    } else if (strcmp(word, "M") == 0) {
        return "Kindness";
    } else if (strcmp(word, "N") == 0) {
        return "Courage";
    } else if (strcmp(word, "O") == 0) {
        return "Determination";
    } else if (strcmp(word, "P") == 0) {
        return "Strength";
    } else if (strcmp(word, "Q") == 0) {
        return "Knowledge";
    } else if (strcmp(word, "R") == 0) {
        return "Wisdom";
    } else if (strcmp(word, "S") == 0) {
        return "Courage";
    } else if (strcmp(word, "T") == 0) {
        return "Faith";
    } else if (strcmp(word, "U") == 0) {
        return "Honesty";
    } else if (strcmp(word, "V") == 0) {
        return "Perseverance";
    } else if (strcmp(word, "W") == 0) {
        return "Gratitude";
    } else if (strcmp(word, "X") == 0) {
        return "Responsibility";
    } else if (strcmp(word, "Y") == 0) {
        return "Fairness";
    } else if (strcmp(word, "Z") == 0) {
        return "Friendship";
    } else {
        return "Unknown";
    }
}

int main() {
    char word[10];
    printf("Enter an alien language word: ");
    scanf("%s", word);

    char* translatedWord = translateAlienWord(word);
    printf("The translated word is: %s\n", translatedWord);

    return 0;
}