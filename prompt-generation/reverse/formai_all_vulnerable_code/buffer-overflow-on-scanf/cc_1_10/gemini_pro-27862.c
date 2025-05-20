//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A list of commonly misspelled words and their correct spellings
const char *misspellings[] = {
    "abreviation", "abbreviation",
    "accomodate", "accommodate",
    "adress", "address",
    "advertisment", "advertisement",
    "afraid", "a fraid",
    "alot", "a lot",
    "beleive", "believe",
    "buisness", "business",
    "course", "coarse",
    "definately", "definitely",
    "description", "discription",
    "embarassment", "embarrassment",
    "enviroment", "environment",
    "especcially", "especially",
    "exagerate", "exaggerate",
    "excelent", "excellent",
    "fascinate", "fascinate",
    "freind", "friend",
    "goverment", "government",
    "harrass", "harass",
    "hurry", "hury",
    "immediatly", "immediately",
    "independant", "independent",
    "inteligent", "intelligent",
    "intresting", "interesting",
    "irresistable", "irresistible",
    "knowlege", "knowledge",
    "lenght", "length",
    "maintanance", "maintenance",
    "mistak", "mistake",
    "neccessary", "necessary",
    "occassion", "occasion",
    "oponent", "opponent",
    "organiztion", "organization",
    "paralel", "parallel",
    "pathetic", "pathetick",
    "persue", "pursue",
    "peice", "piece",
    "peice", "peace",
    "posession", "possession",
    "practical", "practicle",
    "preffer", "prefer",
    "prefferable", "preferable",
    "probabally", "probably",
    "prominent", "prominent",
    "recieve", "receive",
    "recomend", "recommend",
    "reconize", "recognize",
    "referance", "reference",
    "remeber", "remember",
    "resistence", "resistance",
    "responsiblity", "responsibility",
    "rythm", "rhythm",
    "seperate", "separate",
    "simular", "similar",
    "sincerely", "sincerly",
    "someting", "something",
    "speach", "speech",
    "succes", "success",
    "supercede", "supersede",
    "supposidly", "supposedly",
    "suprising", "surprising",
    "temprature", "temperature",
    "tendancy", "tendency",
    "terific", "terrific",
    "there", "their",
    "threshhold", "threshold",
    "togather", "together",
    "untill", "until",
    "wierd", "weird",
    "wont", "won't",
    "wounderful", "wonderful",
    "writen", "written",
};

// The main function
int main(void) {
    // Get the input word from the user
    char word[100];
    printf("Enter a word to check its spelling: ");
    scanf("%s", word);

    // Check if the word is misspelled
    int i;
    for (i = 0; i < sizeof(misspellings) / sizeof(char *); i++) {
        if (strcmp(word, misspellings[i]) == 0) {
            // The word is misspelled, so print the correct spelling
            printf("The correct spelling is: %s\n", misspellings[i + 1]);
            return 0;
        }
    }

    // The word is not misspelled, so print a message
    printf("The word is spelled correctly.\n");
    return 0;
}