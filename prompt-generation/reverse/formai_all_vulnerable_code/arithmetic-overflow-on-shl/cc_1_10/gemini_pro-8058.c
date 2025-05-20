//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: Romeo and Juliet
// Where two hexadecimals meet,
// In code so fair, with characters bittersweet.
// A tale of conversion, Romeo and Juliet,
// Their digits intertwined, a hexadecimate.

#include <stdio.h>

// Romeo, the decimal, with digits bold,
int Romeo = 12345;
// Juliet, the hexadecimal, a mystic hold,
char Juliet[] = "0x3E8";

// The Friar, a function wise,
// Converts Romeo's tale to Juliet's disguise.
int Friar(int Romeo) {
  int Juliet = 0, i = 0, digit;

  while (Romeo != 0) {
    digit = Romeo % 16;
    Juliet |= digit << (4 * i++);
    Romeo /= 16;
  }

  return Juliet;
}

// The Nurse, a function swift,
// Unveils Juliet's secret, a decimal gift.
int Nurse(int Juliet) {
  int Romeo = 0, i = 0, digit;

  while (Juliet != 0) {
    digit = Juliet & 0xF;
    Romeo |= digit << (4 * i++);
    Juliet >>= 4;
  }

  return Romeo;
}

// The Prologue, where the story's told,
int main() {
  int FriarResult = Friar(Romeo); // Romeo's form in hex, a secret to hold.
  int NurseResult = Nurse(Juliet); // Juliet's guise unmasked, a decimal mold.

  // The Epilogue, where the lovers unite,
  printf("Romeo: %d\n", Romeo);
  printf("Juliet: %s\n", Juliet);
  printf("Romeo's Hex: 0x%X\n", FriarResult);
  printf("Juliet's Dec: %d\n", NurseResult);

  // The curtain falls, the tale is through,
  // Romeo and Juliet, a conversion true.
  return 0;
}