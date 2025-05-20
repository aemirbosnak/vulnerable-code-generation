//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surrealist
#include <stdio.h>

// This program generates a surrealist browser plugin that replaces plain text on websites with randomly generated nonsense words

char dictionary[50][10] = {
    "Gloomsquark",
    "Flamboozle",
    "Snortleblitz",
    "Scrambulate",
    "Higglepackle",
    "Spazzenheimer",
    "Borgrumble",
    "Sproingulate",
    "Flibbertigibbet",
    "Frizzlefrazzle",
    "Chizzletwix",
    "Gobstopper",
    "Gibberish",
    "Wibblewobble",
    "Bishbashbosh",
    "Flibbertygibbet",
    "Knickknack",
    "Woopwoop",
    "Nonsensica",
    "Quibbling",
    "Hodgepodge",
    "Razzledazzle",
    "Bamboozle",
    "Skedaddle",
    "Kerfuffle",
    "Rumpus",
    "Whippersnapper",
    "Gobbledygook",
    "Fiddlefaddle",
    "Mumbojumbo",
    "Brouhaha",
    "Flimflam",
    "Hocuspocus",
    "Mishmash",
    "Poppycock",
    "Shenanigans",
    "Skullduggery",
    "Ballyhoo",
    "Cockamamie",
    "Hullabaloo",
    "Jibberjabber",
    "Mumbo-jumbo",
    "Piffle",
    "Tomfoolery",
    "Rigmarole",
    "Hippopotomonstrosesquippedaliophobia",
    "Flibbertypibbit"
};

int main() {
    printf("Initializing the surrealist browser plugin...\n");
    printf("Plugin activated! All plain text on websites will now be replaced with nonsense words from the dictionary.\n\n");

    while (1) {
        printf("Enter a url: ");
        char url[100];
        scanf("%s", url);

        printf("Connecting to %s...\n", url);
        printf("Retrieving page data...\n\n");

        // Replace plain text on the page with nonsense words
        FILE *file;
        file = fopen("page.html", "r");
        char str[100];
        while (fgets(str, 100, file)) {
            for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] == '<' || str[i] == '>') {
                    continue;
                }
                else if (str[i] == ' ') {
                    printf(" ");
                }
                else {
                    int randVal = rand() % 50;
                    printf("%s ", dictionary[randVal]);
                }
            }
            printf("\n");
        }
        fclose(file);

        printf("\n\nWould you like to enter another url? (y/n)\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    printf("\nExiting the surrealist browser plugin...\n");
    return 0;
}