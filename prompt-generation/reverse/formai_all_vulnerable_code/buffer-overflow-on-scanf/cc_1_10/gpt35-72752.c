//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: invasive
#include <stdio.h>
#include <string.h>

/* Alien Language Dictionary */
const char* ALIEN_WORDS[] = {
    "ghhfd", "eyruo", "kqpld", "tfdja", "xbmzn", 
    "jbmwq", "ionve", "fnoyt", "tzncv", "psakl"
};

/* Alien Language Keys */
const char* ALIEN_KEYS[] = {
    "gh#45", "ey$12", "kp!09", "tf@23", "xb%67", 
    "jb^34", "io*78", "fn(01", "tz)56", "ps_89"
};

char* translate(char* text) {
    int i, j, found = 0;
    char* alien_word = "";
    
    /* Check if the text has a valid Alien Language Key */
    for(i = 0; i < 10; ++i) {
        if(strncmp(text, ALIEN_KEYS[i], 5) == 0) {
            found = 1;
            alien_word = ALIEN_WORDS[i];
            break;
        }
    }

    /* If a valid key is found, translate the text */
    if(found) {
        for(j = 5; j < strlen(text); ++j) {
            text[j-5] = alien_word[(int)(text[j]-'a')];
        }
        /* Append a '.' at the end of the translated text */
        text[strlen(text)-5] = '.';
    }
    
    /* Return the translated (or original) text */
    return text;
}

int main(void) {
    char text[100];
    
    printf("Enter some Alien Language text: ");
    scanf("%[^\n]s", text);
    
    char* translated_text = translate(text);
    
    printf("Translated text: %s\n", translated_text);
    
    return 0;
}