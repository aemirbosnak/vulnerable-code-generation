//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORDS 100
#define TIMER 60

// Array of words
char *words[WORDS] = {
    "aforementioned", "alacrity", "ambrosial", "antiquated", "august", "auspicious", "bedecked", "benign", "bucolic",
    "capricious", "celerity", "chivalrous", "circumspect", "complaisant", "convivial", "decorous", "deferential",
    "delectable", "diminutive", "discerning", "distinguished", "dulcet", "eloquent", "enchanting", "ephemeral",
    "equanimity", "ethereal", "exquisite", "facetious", "felicitous", "florid", "fortuitous", "fragile", "gallant",
    "gregarious", "halcyon", "harmonious", "heavenly", "idyllic", "illustrious", "immaculate", "impeccable", "imperturbable",
    "incomparable", "indomitable", "ineffable", "ingenious", "ingenuous", "insipid", "insouciant", "intangible", "invigorating",
    "irresistible", "jubilant", "lambent", "languid", "luminous", "magnanimous", "majestic", "malicious", "mellifluous",
    "melodious", "mercurial", "mesmerizing", "miraculous", "momentous", "mundane", "mystical", "nefarious", "nocturnal",
    "opulent", "ornate", "palatial", "parsimonious", "pastoral", "patrician", "peculiar", "pellucid", "penchant",
    "perennial", "perspicacious", "phantasmagorical", "picturesque", "piquant", "placid", "platitudinous", "pleasing",
    "plenteous", "poetic", "poignant", "pristine", "prodigious", "propitious", "quaint", "radiant", "rapture", "rarefied",
    "regale", "refulgent", "resplendent", "reverent", "rhapsodic", "rustic", "sagacious", "salubrious", "salutary",
    "sanctimonious", "sanguine", "sapient", "savory", "scintillating", "seraphic", "serene", "sidereal", "singular",
    "sonorous", "spectacular", "splendid", "sporadic", "sprightly", "stately", "steadfast", "sublime", "sumptuous",
    "superb", "sylvan", "taciturn", "tangible", "tantalizing", "tempestuous", "tenacious", "tender", "tenuous", "terrestrial",
    "timorous", "tranquil", "transcendental", "translucent", "transmundane", "transpicuous", "tremulous", "tumultuous",
    "ubiquitous", "unassuming", "uncanny", "uncommon", "unctuous", "undulating", "unequivocal", "unfathomable", "unforgettable",
    "unimpeachable", "unison", "unparalleled", "unpretentious", "unquenchable", "unsullied", "unyielding", "utopian",
    "vacillating", "vagrant", "valor", "vapid", "variegated", "velvety", "venerable", "venial", "veracious", "verdant",
    "vernacular", "veritable", "versatile", "vestige", "vivacious", "voluminous", "vortex", "wanton", "winsome", "zealous",
    "zenith", "zephyr", "zydeco"
};

// Function to generate a random word
char *get_random_word() {
    return words[rand() % WORDS];
}

// Function to compare two strings
int compare_strings(char *str1, char *str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }

        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the current time
    time_t start_time = time(NULL);

    // Generate a random word
    char *word = get_random_word();

    // Print the word to the screen
    printf("Type the following word as quickly as you can:\n\n%s\n\n", word);

    // Get the user's input
    char input[100];
    scanf("%s", input);

    // Get the current time
    time_t end_time = time(NULL);

    // Calculate the time taken to type the word
    double time_taken = difftime(end_time, start_time);

    // Compare the user's input to the original word
    int correct = compare_strings(input, word);

    // Print the results
    if (correct) {
        printf("\nCongratulations! You typed the word correctly in %f seconds.\n", time_taken);
    } else {
        printf("\nSorry, you typed the word incorrectly.\n");
    }

    return 0;
}