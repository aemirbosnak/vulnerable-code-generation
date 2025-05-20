//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>

// Our fair Verona, where we lay our scene
int main(void) {
  // The star-crossed lovers
  float fahrenheit, celsius;

  // A prologue to our tale of woe
  printf("Hark, what light through yonder window breaks?\n");
  printf("It is the east, and Juliet is the sun.\n");

  // Romeo, seeking his Juliet
  printf("O, speak again, bright angel! for thou art\n");
  printf("As glorious to this night, being o'er my head,\n");
  printf("As is a winged messenger of heaven\n");
  printf("Unto the white-upturned wondering eyes\n");
  printf("Of mortals that fall back to gaze on him,\n");
  printf("When he bestrides the lazy-pacing clouds\n");
  printf("And sails upon the bosom of the air.\n");

  // Juliet, responding to her Romeo
  printf("O Romeo, Romeo! wherefore art thou Romeo?\n");
  printf("Deny thy father and refuse thy name;\n");
  printf("Or, if thou wilt not, be but sworn my love,\n");
  printf("And I'll no longer be a Capulet.\n");

  // Romeo, proposing a conversion
  printf("My mistress' eyes are nothing like the sun;\n");
  printf("Coral is far more red than her lips' red;\n");
  printf("If snow be white, why then her breasts are dun;\n");
  printf("If hairs be wires, black wires grow on her head.\n");
  printf("I have seen roses damasked, red and white,\n");
  printf("But no such roses see I in her cheeks;\n");
  printf("And in some perfumes is there more delight\n");
  printf("Than in the breath that from my mistress reeks.\n");
  printf("I love to hear her speak, yet well I know\n");
  printf("That music hath a far more pleasing sound;\n");
  printf("I grant I never saw a goddess go;\n");
  printf("My mistress, when she walks, treads on the ground.\n");
  printf("And yet, by heaven, I think my love as rare\n");
  printf("As any she belied with false compare.\n");

  // Juliet, accepting the conversion
  printf("O, wert thou in the cold, cold ground,\n");
  printf("Thou art as fair and as cold as my mistress is.\n");
  printf("But wherefore, Romeo, didst thou splice our nuts?\n");
  printf("Wouldst thou not compute my weight in stones?\n");
  printf("Or measure my length with yardsticks, slender?\n");
  printf("Or estimate my size in cubic feet?\n");
  printf("For thou art like a mathematician,\n");
  printf("And I a simple maid, yet charmed by thee.\n");

  // Romeo, performing the conversion
  printf("With all my heart, my dearest Juliet.\n");
  printf("Tell me, what is thy weight in pounds?\n");
  scanf("%f", &fahrenheit);
  celsius = (fahrenheit - 32) * 5 / 9;
  printf("Thy weight in stones is %.2f stones.\n", celsius / 14);

  // Juliet, pleased with the conversion
  printf("Ah, my Romeo, thou art a clever lad.\n");
  printf("Now, tell me, what is my length in yards?\n");
  scanf("%f", &fahrenheit);
  celsius = fahrenheit * 0.9144;
  printf("Thy length in yards is %.2f yards.\n", celsius);

  // Romeo, continuing the conversion
  printf("And finally, my love, what is thy size in cubic feet?\n");
  scanf("%f", &fahrenheit);
  celsius = fahrenheit * 0.0283168;
  printf("Thy size in cubic feet is %.2f cubic feet.\n", celsius);

  // Juliet, enraptured by Romeo's conversion
  printf("O Romeo, Romeo, thou hast made me whole.\n");
  printf("Now, I know my weight, my length, and my size.\n");
  printf("And all thanks to thee, my clever love.\n");

  // A happy ending to our tale of love and conversion
  printf("Thus, Romeo and Juliet were wed,\n");
  printf("And lived happily ever after.\n");
  printf("The end.\n");

  return 0;
}