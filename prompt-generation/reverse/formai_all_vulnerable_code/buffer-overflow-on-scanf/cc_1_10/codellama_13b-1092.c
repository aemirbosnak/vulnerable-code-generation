//Code Llama-13B DATASET v1.0 Category: Automated Fortune Teller ; Style: real-life
/*
 * Automated Fortune Teller
 *
 * This program will ask the user for their birthdate, and then provide them with a personalized fortune based on their astrological sign.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LENGTH 30
#define NUM_SIGNS 12

typedef struct {
    char name[MAX_NAME_LENGTH];
    int start_month;
    int start_day;
} Sign;

void print_sign(Sign sign) {
    printf("Your sign is %s!\n", sign.name);
}

int main() {
    Sign signs[NUM_SIGNS] = {
        {"Aries", 3, 21},
        {"Taurus", 4, 20},
        {"Gemini", 5, 21},
        {"Cancer", 6, 21},
        {"Leo", 7, 23},
        {"Virgo", 8, 23},
        {"Libra", 9, 23},
        {"Scorpio", 10, 23},
        {"Sagittarius", 11, 22},
        {"Capricorn", 12, 22},
        {"Aquarius", 1, 20},
        {"Pisces", 2, 19}
    };

    char name[MAX_NAME_LENGTH];
    int month, day;

    printf("What is your birthdate? (mm/dd) ");
    scanf("%d/%d", &month, &day);

    for (int i = 0; i < NUM_SIGNS; i++) {
        if (month == signs[i].start_month && day >= signs[i].start_day) {
            print_sign(signs[i]);
            break;
        }
    }

    return 0;
}