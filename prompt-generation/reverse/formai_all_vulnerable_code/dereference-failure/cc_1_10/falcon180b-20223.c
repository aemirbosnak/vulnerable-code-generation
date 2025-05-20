//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *input = argv[1];
    char *output = argv[2];
    size_t len = strlen(input);
    int base = 0;
    size_t i = 0;
    double num = 0;
    char *endptr = NULL;
    char *ptr = strchr(input, '.');

    if (ptr!= NULL) {
        base = 10;
    } else {
        ptr = strchr(input, 'C');
        if (ptr!= NULL) {
            base = 1;
            ptr += 2;
        } else {
            ptr = strchr(input, 'F');
            if (ptr!= NULL) {
                base = 1;
                ptr += 2;
            } else {
                return 1;
            }
        }
    }

    num = strtod(ptr, &endptr);
    if (endptr == NULL || *endptr!= '\0') {
        return 1;
    }

    switch (base) {
        case 1:
            num = (num - 32) * 5 / 9;
            break;
        case 10:
            num = num * 9 / 5 + 32;
            break;
        default:
            return 1;
    }

    snprintf(output, len, "%.2f", num);
    return 0;
}