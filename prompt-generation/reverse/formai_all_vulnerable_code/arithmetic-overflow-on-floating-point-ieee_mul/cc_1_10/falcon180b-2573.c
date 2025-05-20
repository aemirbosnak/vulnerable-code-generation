//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONVERSIONS 1000

struct conversion {
    char *from_unit;
    char *to_unit;
    double factor;
};

int main() {
    char input[100];
    char *delimiter = " ";
    char *token;
    struct conversion conversions[MAX_CONVERSIONS];
    int num_conversions = 0;

    // Initialize default conversions
    conversions[num_conversions].from_unit = "meter";
    conversions[num_conversions].to_unit = "feet";
    conversions[num_conversions].factor = 3.28084;
    num_conversions++;

    conversions[num_conversions].from_unit = "meter";
    conversions[num_conversions].to_unit = "inch";
    conversions[num_conversions].factor = 39.3701;
    num_conversions++;

    conversions[num_conversions].from_unit = "meter";
    conversions[num_conversions].to_unit = "centimeter";
    conversions[num_conversions].factor = 100;
    num_conversions++;

    while(1) {
        printf("Enter a conversion (e.g. 5 meter to feet): ");
        fgets(input, sizeof(input), stdin);
        token = strtok(input, delimiter);
        if(token == NULL) {
            continue;
        }
        if(strcasecmp(token, "exit") == 0) {
            break;
        }
        conversions[num_conversions].from_unit = strdup(token);
        conversions[num_conversions].to_unit = strdup(strtok(NULL, delimiter));
        conversions[num_conversions].factor = strtod(strtok(NULL, delimiter), NULL);
        num_conversions++;
    }

    while(1) {
        printf("Enter a value to convert: ");
        fgets(input, sizeof(input), stdin);
        token = strtok(input, delimiter);
        if(token == NULL) {
            continue;
        }
        int i;
        for(i = 0; i < num_conversions; i++) {
            if(strcasecmp(conversions[i].from_unit, token) == 0) {
                double value = strtod(strtok(NULL, delimiter), NULL);
                double result = value * conversions[i].factor;
                printf("%f %s = %f %s\n", value, token, result, conversions[i].to_unit);
                break;
            }
        }
        if(i == num_conversions) {
            printf("Invalid unit\n");
        }
    }

    return 0;
}