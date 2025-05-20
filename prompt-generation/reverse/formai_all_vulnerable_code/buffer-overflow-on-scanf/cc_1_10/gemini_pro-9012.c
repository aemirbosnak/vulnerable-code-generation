//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define DREAM_START              "The curtains of reality flutter open, revealing a realm where numbers dance in a delirious ballet."
#define DREAM_END                "As the ethereal curtains close, the slumbering digits awaken, carrying with them the echoes of a surreal calculation."
#define OPERATION_PROMPT         "In the murmuring depths of your mind, what operation beckons?"
#define OPERAND_PROMPT(num)      "Unveil the ethereal number %d, whose essence shimmers in your consciousness."
#define RESULT_DISPLAY(num)      "In the numinous tapestry of the cosmos, the result unfurls: %f."

void whisper(const char *message) {
    printf("%s\n", message);
}

double dream() {
    int operation_index;
    double operands[2];

    whisper(DREAM_START);

    whisper(OPERATION_PROMPT);
    scanf("%d", &operation_index);

    for (int i = 0; i < 2; i++) {
        whisper(OPERAND_PROMPT(i + 1));
        scanf("%lf", &operands[i]);
    }

    double result;
    switch (operation_index) {
        case 1: result = operands[0] + operands[1]; break;
        case 2: result = operands[0] - operands[1]; break;
        case 3: result = operands[0] * operands[1]; break;
        case 4: result = operands[0] / operands[1]; break;
        case 5: result = pow(operands[0], operands[1]); break;
        case 6: result = sqrt(operands[0]); break;
        case 7: result = sin(operands[0]); break;
        case 8: result = cos(operands[0]); break;
        case 9: result = tan(operands[0]); break;
        default: whisper("The operation you seek evades the grasp of this celestial realm."); return 0;
    }

    whisper(RESULT_DISPLAY(result));
    whisper(DREAM_END);

    return result;
}

int main() {
    dream();
    return 0;
}