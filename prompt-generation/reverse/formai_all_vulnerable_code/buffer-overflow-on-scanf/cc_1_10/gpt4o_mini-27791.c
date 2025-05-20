//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_welcome_message() {
    printf("=====================================\n");
    printf("  Welcome, noble seeker of truths!  \n");
    printf("  Step forth into the realm of fate! \n");
    printf("=====================================\n");
}

void print_farewell_message() {
    printf("=====================================\n");
    printf("  May the winds of fortune guide you! \n");
    printf("  Until we meet again!              \n");
    printf("=====================================\n");
}

void show_zodiac_signs() {
    printf("\nChoose thy fateful zodiac sign from the list below:\n");
    printf("1. Aries          - The Ram\n");
    printf("2. Taurus         - The Bull\n");
    printf("3. Gemini         - The Twins\n");
    printf("4. Cancer         - The Crab\n");
    printf("5. Leo            - The Lion\n");
    printf("6. Virgo          - The Maiden\n");
    printf("7. Libra          - The Scales\n");
    printf("8. Scorpio        - The Scorpion\n");
    printf("9. Sagittarius    - The Archer\n");
    printf("10. Capricorn     - The Goat\n");
    printf("11. Aquarius      - The Water Bearer\n");
    printf("12. Pisces        - The Fish\n");
}

const char* get_fortune(int choice) {
    const char* fortunes[] = {
        "Today is your day to conquer!",
        "Beware of shadows lurking in corners!",
        "A long-awaited letter shall arrive.",
        "Your true love may be closer than you think.",
        "Fortune favors the brave - act wisely!",
        "An old friend will return to visit.",
        "Embrace change; it shall bring luck.",
        "A golden opportunity presents itself!",
        "Beware of the ides of March, keep your guard!",
        "Treasure the moments - they define you.",
        "A feast is on the horizon, prepare thyself!",
        "A journey of a thousand miles begins with a single step."
    };
    return fortunes[choice % 12]; // Get a fortune based on zodiac sign
}

int main() {
    int choice;
    
    srand(time(NULL)); // Seed the random number generator
    
    print_welcome_message();
    show_zodiac_signs();
    
    printf("Enter the number corresponding to thy zodiac sign (1-12): ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > 12) {
        printf("O fair seeker, thou hast entered an invalid number. Please try again!\n");
    } else {
        const char* fortune = get_fortune(choice);
        printf("=====================================\n");
        printf("Your fortune for the day is:\n");
        printf("%s\n", fortune);
        printf("=====================================\n");
    }
    
    print_farewell_message();
    return 0;
}