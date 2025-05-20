//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hexadecimal color code>\n", argv[0]);
        return 1;
    }

    char *colorCode = argv[1];
    char *r = strstr(colorCode, "00");
    char *g = strstr(r, "00");
    char *b = strstr(g, "00");

    if (!r ||!g ||!b) {
        printf("Invalid color code\n");
        return 1;
    }

    char *rr = strstr(r, "00");
    char *gg = strstr(g, "00");
    char *bb = strstr(b, "00");

    if (!rr ||!gg ||!bb) {
        printf("Invalid color code\n");
        return 1;
    }

    int rr_val = strtol(rr + 2, NULL, 16);
    int gg_val = strtol(gg + 2, NULL, 16);
    int bb_val = strtol(bb + 2, NULL, 16);

    if (rr_val > 255 || gg_val > 255 || bb_val > 255) {
        printf("Invalid color code\n");
        return 1;
    }

    char *rr_str = malloc(4);
    char *gg_str = malloc(4);
    char *bb_str = malloc(4);
    sprintf(rr_str, "%02X", rr_val);
    sprintf(gg_str, "%02X", gg_val);
    sprintf(bb_str, "%02X", bb_val);

    printf("%s\n", colorCode);
    printf("R: %s\n", rr_str);
    printf("G: %s\n", gg_str);
    printf("B: %s\n", bb_str);

    free(rr_str);
    free(gg_str);
    free(bb_str);

    return 0;
}