//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>

// Our fair Verona, where we lay our scene,
// A city of love, where hearts entwine.
int main() {
  // Romeo, oh Romeo, wherefore sendest thou not?
  // Juliet, my love, I answer to thy plea.

  // But hark! What news from distant lands?
  // A tale of units, a puzzle to be solved.

  // From inches to feet, a simple stride,
  // Or yards to miles, a grand leap indeed.
  float inches, feet, yards, miles;

  // "Two households, both alike in dignity,"
  // But different in their measurements, it seems.

  // "If thou art Romeo, throw thy glove,
  // And I'll convert thy inches into feet."
  printf("My fair Juliet, prithee tell me true,\n");
  printf("How many inches wouldst thou like to convert?\n");
  scanf("%f", &inches);

  feet = inches / 12;
  printf("Thus, %f inches become %f feet.\n", inches, feet);

  // "If thou art Romeo, throw thy cap,
  // And I'll convert thy feet into yards."
  printf("And now, my love, a further task I pray,\n");
  printf("How many feet wouldst thou like to convert?\n");
  scanf("%f", &feet);

  yards = feet / 3;
  printf("Therefore, %f feet become %f yards.\n", feet, yards);

  // "If thou art Romeo, throw thy hat,
  // And I'll convert thy yards into miles."
  printf("One final test, my dearest Juliet,\n");
  printf("How many yards wouldst thou like to convert?\n");
  scanf("%f", &yards);

  miles = yards / 1760;
  printf("And so, %f yards become %f miles.\n", yards, miles);

  // "O Romeo, Romeo, wherefore art thou Romeo?"
  // "And Juliet, Juliet, O, wherefore art thou Juliet?"

  // "Deny thy father and refuse thy name,
  // And for thy name, which is no part of thee,
  // Take thou my heart, and for it, let me have thine."

  // Our love transcends all earthly bounds,
  // And so too does our knowledge of units.
  printf("Now, my fair Juliet, we understand,\n");
  printf("The world of measurements, hand in hand.\n");

  return 0;
}