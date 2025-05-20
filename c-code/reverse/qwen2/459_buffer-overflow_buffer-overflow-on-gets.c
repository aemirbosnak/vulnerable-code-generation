#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[256];
    char output[512] = "";
    const char* replacements[] = {"FUTURISTIC", "ADVANCED", "INNOVATIVE", "TRANSCENDENT", "EMERGING", "PIONEERING", "REVOLUTIONARY", "BREAKTHROUGH", "SYNTHETIC", "CYBERNETIC"};
    int i, j;

    fgets(input, sizeof(input), stdin);
    for (i = 0; input[i]; i++) {
        if (input[i] == ' ') {
            strcat(output, "SPACE");
        } else {
            j = rand() % 10;
            strcat(output, replacements[j]);
        }
    }

    printf("%s\n", output);

    return 0;
}
