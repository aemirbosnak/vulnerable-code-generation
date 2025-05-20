//FormAI DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main() {
    char hexCode[7];
    int decCode[3];
    printf("Enter a 6 digit Hexadecimal Color Code: ");
    scanf("%s", hexCode);

    /* Converting Hexadecimal to Decimal */
    decCode[0] = ((int) hexCode[0] - 48) * 16 + ((int) hexCode[1] - 48);
    decCode[1] = ((int) hexCode[2] - 48) * 16 + ((int) hexCode[3] - 48);
    decCode[2] = ((int) hexCode[4] - 48) * 16 + ((int) hexCode[5] - 48);

    /* Converting Decimal to Binary */
    char binCode[25];
    for (int i=0; i<3; i++) {
        int quotient = decCode[i];
        int remainder, j=0;
        char revBin[9];
        while (quotient > 0) {
            remainder = quotient % 2;
            revBin[j++] = remainder + 48;
            quotient /= 2;
        }
        while (j < 8) {
            revBin[j++] = '0';
        }

        /* Reversing the Binary string */
        for (int k=0; k<8; k++) {
            binCode[i * 8 + k] = revBin[7-k];
        }
    }

    /* Reversing the Binary string */
    int j;
    char reverseBin[25];
    for (int i=0, j=strlen(binCode)-1; i<strlen(binCode); i++, j--) {
        reverseBin[i] = binCode[j];
    }

    /* Converting Binary to Decimal */
    int newDecCode[3];
    for (int i=0; i<3; i++) {
        newDecCode[i] = 0;
        for (int j=0; j<8; j++) {
            if (reverseBin[i*8+j] == '1') {
                newDecCode[i] += 1 << j;
            }
        }
    }

    /* Printing the RGB Color Code */
    printf("The RGB Color Code for %s is %d,%d,%d.", hexCode, newDecCode[0], newDecCode[1], newDecCode[2]);
    return 0;
}