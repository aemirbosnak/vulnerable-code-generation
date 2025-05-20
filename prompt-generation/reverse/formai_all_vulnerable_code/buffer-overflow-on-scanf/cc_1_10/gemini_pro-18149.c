//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: futuristic
// Welcome to the NeXt-Gen Password Security Sentinel!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_PASS_LEN 8
#define MAX_PASS_LEN 32

// Intergalactic Strength Scale.
typedef enum {
    PASSWORD_WEAK, // 0
    PASSWORD_FAIR, // 1
    PASSWORD_MODERATE, // 2
    PASSWORD_STRONG, // 3
    PASSWORD_NEBULA // 4
} PassStrength;

// Cybernetic Regex Array.
char passRegex[][20] = {
    "[a-zA-Z0-9]", // Basic alphanumeric.
    "[a-zA-Z0-9_!@#$%^&*-+=?]", // Extended characters.
    "[a-zA-Z0-9_!@#$%^&*-+=?<>]", // More complex.
    "[a-zA-Z0-9_!@#$%^&*-+=?<>\\s]" // Galactic level!
};

// Quantum Analyzer Algorithm.
PassStrength analyzePassword(char *pass) {
    int len = strlen(pass);
    int strength = PASSWORD_WEAK;

    // Validate length.
    if (len < MIN_PASS_LEN || len > MAX_PASS_LEN) {
        return PASSWORD_WEAK;
    }

    // Scan for regex matches.
    for (int i = 0; i < 4; i++) {
        if (!regexMatch(pass, passRegex[i])) {
            strength = PASSWORD_WEAK;
            break;
        } else {
            strength++;
        }
    }

    return strength;
}

// Subspace Regex Engine.
int regexMatch(char *pass, char *pattern) {
    int passLen = strlen(pass);
    int patternLen = strlen(pattern);
    int matches = 0;

    for (int i = 0; i < passLen; i++) {
        char c = pass[i];
        for (int j = 0; j < patternLen; j++) {
            char p = pattern[j];
            if (p == c || p == '.' || p == '-' || p == '\\') {
                matches++;
                break;
            }
        }
    }

    return matches == passLen;
}

// Pulsar Console Interface.
int main() {
    // Initialize the Cyberspace.
    char pass[MAX_PASS_LEN + 1];

    // Engage the Quantum Scanner.
    printf("Salutations, valiant Cyberspace Navigator!\n");
    printf("Present your Galactic Credentials: ");
    scanf("%s", pass);

    // Analyze the Cosmic Password.
    PassStrength strength = analyzePassword(pass);

    // Display the Cosmic Strength Assessment.
    switch (strength) {
        case PASSWORD_WEAK:
            printf("Alert! Your Galactic Code is as fragile as a Neutron Star.\n");
            printf("Consider reinforcing it with more celestial essence.\n");
            break;
        case PASSWORD_FAIR:
            printf("Your Galactic Code exhibits signs of Stellar Radiance.\n");
            printf("With some refinement, it shall ascend to greater heights.\n");
            break;
        case PASSWORD_MODERATE:
            printf("Behold, your Galactic Code shines like a Quantum Sun!\n");
            printf("Yet, its full potential awaits deeper exploration.\n");
            break;
        case PASSWORD_STRONG:
            printf("Your Galactic Code is a Fortress of Defiance!\n");
            printf("It resonates with the power of a Black Hole.\n");
            break;
        case PASSWORD_NEBULA:
            printf("Transcendent! Your Galactic Code is a Nebula of Impenetrable Darkness.\n");
            printf("All who behold it shall be awestruck by its cosmic majesty.\n");
            break;
    }

    // Return to Hyperspace.
    return 0;
}