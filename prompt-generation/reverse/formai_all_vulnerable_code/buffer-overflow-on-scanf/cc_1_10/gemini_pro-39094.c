//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *alien;
    char *english;
} Translation;

Translation translations[] = {
    {"at", "to"},
    {"be", "is"},
    {"co", "with"},
    {"de", "of"},
    {"di", "for"},
    {"e", "and"},
    {"en", "in"},
    {"es", "you"},
    {"et", "it"},
    {"fe", "me"},
    {"he", "him"},
    {"ho", "she"},
    {"hu", "her"},
    {"i", "I"},
    {"la", "the"},
    {"le", "him"},
    {"li", "her"},
    {"lo", "it"},
    {"ma", "my"},
    {"me", "me"},
    {"mi", "mine"},
    {"na", "our"},
    {"ne", "us"},
    {"ni", "our"},
    {"o", "of"},
    {"pa", "by"},
    {"pe", "for"},
    {"pi", "with"},
    {"po", "to"},
    {"qu", "who"},
    {"re", "are"},
    {"sa", "has"},
    {"se", "his"},
    {"si", "her"},
    {"so", "its"},
    {"ta", "have"},
    {"te", "has"},
    {"ti", "had"},
    {"to", "that"},
    {"tu", "you"},
    {"va", "come"},
    {"ve", "came"},
    {"vi", "come"},
    {"vo", "going"},
    {"wa", "want"},
    {"we", "went"},
    {"wi", "want"},
    {"wo", "wanted"},
    {"xa", "say"},
    {"xe", "said"},
    {"xi", "say"},
    {"xo", "saying"},
    {"ya", "yes"},
    {"ye", "yes"},
    {"yi", "yes"},
    {"yo", "yes"},
    {NULL, NULL}
};

char *translate(char *alien) {
    int i;
    for (i = 0; translations[i].alien != NULL; i++) {
        if (strcmp(alien, translations[i].alien) == 0) {
            return translations[i].english;
        }
    }
    return NULL;
}

int main() {
    char alien[100];
    char *english;

    printf("Enter an Alien word: ");
    scanf("%s", alien);

    english = translate(alien);
    if (english == NULL) {
        printf("Unknown Alien word: %s\n", alien);
    } else {
        printf("English translation: %s\n", english);
    }

    return 0;
}