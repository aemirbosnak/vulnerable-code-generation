//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: unmistakable
#include<stdio.h>

int main() {
    char input[100];
    char output[16][200];
    int i, j, k, len;
    const char *asc_art[] = {
        "  _____                        ____             _",
        " |_   _|___ ___ _ __  ___    / ___| _   _  ___| |_ ___  _ __",
        "   | |/ __/ _ \\ '_ \\/ __|  | |  _ | | | |/ __| __/ _ \\| '__|",
        "   | | (_|  __/ | | \\__ \\  | |_| || |_| | (__| || (_) | |",
        " _ |_|\\___\\___|_| |_|___/   \\____| \\__,_|\\___|\\__\\___/|_|",
        " | |___   __ _(_)_ __   __| | ___ _ __ __ _| |_ ___  _ __",
        " | / __| / _` | | '_ \\ / _` |/ _ \\ '__/ _` | __/ _ \\| '__|",
        " | \\__ \\| (_| | | | | | (_| |  __/ | | (_| | || (_) | |",
        " |_|___/ \\__, |_|_| |_|\\__,_|\\___|_|  \\__,_|\\__\\___/|_|",
        "         |___/",
    };
    
    printf("Enter the desired text: ");
    fgets(input, sizeof(input), stdin);
    
    len = strlen(input);
    input[len - 1] = '\0';  // Replace the newline character with null character
    
    // Converting to upper case
    for(i = 0; i < len; i++) {
        input[i] = toupper(input[i]);
    }
    
    // Copying the ASCII art corresponding to each uppercase letter
    for(i = 0; i < len; i++) {
        if(input[i] == ' ') {
            for(j = 0; j < 10; j++) {
                for(k = 0; k < strlen(asc_art[j]); k++) {
                    output[j][i*6 + k] = ' ';
                }
                output[j][i*6 + k] = '\0';
            }
        }
        else {
            for(j = 0; j < 10; j++) {
                for(k = 0; k < 5; k++) {
                    output[j][i*6 + k] = asc_art[j][input[i]-'A'*5 + k];
                }
                output[j][i*6 + k] = ' ';
                output[j][i*6 + k + 1] = '\0';
            }
        }
    }
    
    // Printing the output ASCII art
    for(i = 0; i < 10; i++) {
        for(j = 0; j < len*6; j++) {
            printf("%c", output[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}