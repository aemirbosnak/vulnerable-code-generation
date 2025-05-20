//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define CONVERT_LENGTH 1
#define CONVERT_WEIGHT 2
#define CONVERT_TEMPERATURE 3

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <value> <from> <to>\n", argv[0]);
        return EXIT_FAILURE;
    }

    double value = atof(argv[1]);
    int from = atoi(argv[2]);
    int to = atoi(argv[3]);

    switch (from) {
        case CONVERT_LENGTH:
            switch (to) {
                case CONVERT_LENGTH:
                    printf("%f %s\n", value, argv[1]);
                    break;
                case CONVERT_WEIGHT:
                    printf("%f %s\n", value * 2.205, "lbs");
                    break;
                case CONVERT_TEMPERATURE:
                    printf("%f %s\n", value * 1.8 + 32, "°F");
                    break;
            }
            break;
        case CONVERT_WEIGHT:
            switch (to) {
                case CONVERT_LENGTH:
                    printf("%f %s\n", value / 2.205, "kg");
                    break;
                case CONVERT_WEIGHT:
                    printf("%f %s\n", value, argv[1]);
                    break;
                case CONVERT_TEMPERATURE:
                    printf("%f %s\n", value * 1.8 + 32, "°F");
                    break;
            }
            break;
        case CONVERT_TEMPERATURE:
            switch (to) {
                case CONVERT_LENGTH:
                    printf("%f %s\n", (value - 32) / 1.8, "m");
                    break;
                case CONVERT_WEIGHT:
                    printf("%f %s\n", (value - 32) / 1.8 * 0.454, "kg");
                    break;
                case CONVERT_TEMPERATURE:
                    printf("%f %s\n", value, argv[1]);
                    break;
            }
            break;
    }

    return EXIT_SUCCESS;
}