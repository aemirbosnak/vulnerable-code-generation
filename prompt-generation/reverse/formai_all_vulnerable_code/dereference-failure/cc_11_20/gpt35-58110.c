//FormAI DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        exit(1);
    }

    char *message = argv[1];
    int len = strlen(message);
    int upper_count = 0;
    int digit_count = 0;
    int special_count = 0;
    int space_count = 0;
    int total_count = 0;

    for(int i = 0; i < len; i++) {
        char c = message[i];
        if(c >= 'A' && c <= 'Z') {
            upper_count++;
        }
        else if(c >= '0' && c <= '9') {
            digit_count++;
        }
        else if(c == ' ') {
            space_count++;
        }
        else if(c == '@' || c == '$' || c == '#') {
            special_count++;
        }
        total_count++;
    }

    float upper_percent = (float) upper_count/total_count;
    float digit_percent = (float) digit_count/total_count;
    float special_percent = (float) special_count/total_count;
    float space_percent = (float) space_count/total_count;

    if(upper_percent >= 0.5 || digit_percent >= 0.2 || special_percent >= 0.1 || space_percent >= 0.25) {
        printf("Potential spam detected!");
    }
    else {
        printf("Message is safe.");
    }

    return 0;
}