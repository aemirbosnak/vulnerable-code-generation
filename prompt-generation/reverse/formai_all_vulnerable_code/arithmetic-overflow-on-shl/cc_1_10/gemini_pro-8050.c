//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: visionary
// A Glimpse into the Enigmatic Realm of Bits

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main(void) {
  // Unveiling the Essence of a Bit
  printf("A solitary bit, a whisper in the digital void\n");
  int bit = 1;
  printf("As an integer, it unfolds into: %d\n\n", bit);

  // Binary's Enchanting Dance
  printf("Now, let us unveil its binary form, a secret symphony\n");
  printf("In its binary guise, it masquerades as: %d\n\n", bit << 31 >> 31);

  // Masking the Bit's Ethereal Presence
  printf("To discern its true nature, we don a mask\n");
  uint32_t mask = 1 << 31;
  printf("The mask, a potent sentinel: %u\n", mask);
  printf("And behold, the masked bit emerges: %u\n\n", bit & mask);

  // Conjuring a Binary Mosaic
  printf("Now, let us conjure a mosaic of bits, a digital tapestry\n");
  uint32_t mosaic = 0xABCDEF;
  printf("In its hexadecimal glory, the mosaic paints: %x\n", mosaic);

  // Shifting the Mosaic's Intricate Patterns
  printf("With a sorcerer's touch, we shift the mosaic's patterns\n");
  mosaic = mosaic >> 4;
  printf("Shifted to the right by 4, the mosaic now whispers: %x\n\n", mosaic);

  // Inverting the Mosaic's Binary Threads
  printf("Now, let us invert the mosaic, turning light into shadow\n");
  mosaic = ~mosaic;
  printf("In its inverted form, the mosaic reveals its hidden secrets: %x\n\n", mosaic);

  // Unmasking the Mosaic's Enigmatic Depths
  printf("To unveil the mosaic's true nature, we remove its mask\n");
  mosaic = mosaic & 0xF0F0F0F0;
  printf("Unmasked, the mosaic's depths are revealed: %x\n\n", mosaic);

  // Exploring the Constants of the Bitverse
  printf("In this realm of bits, constants reign supreme\n");
  printf("The smallest of all, the mighty CHAR_BIT: %d\n", CHAR_BIT);
  printf("The limits of signed integers, wrapped in mystery: %d and %d\n", INT_MIN, INT_MAX);
  printf("The vast expanse of unsigned integers, unbounded by frontiers: %u and %u\n\n", 0, UINT_MAX);

  // Unveiling the Power of Bit Manipulation
  printf("With bitwise sorcery, we unlock the power to reshape integers\n");
  int num = 1234;
  printf("In its mortal form, the number stands as: %d\n", num);
  printf("Flipping the bits, transforming form: %u\n", ~num);
  printf("Shifting left by 4, the number ascends: %d\n", num << 4);
  printf("And right by 4, it descends: %d\n\n", num >> 4);

  // Conjuring a Bitwise Calculator
  printf("Behold, the bitwise calculator, a tool of immense power\n");
  int a = 12, b = 34;
  printf("A and B, entwined in bitwise harmony: %d\n", a & b);
  printf("A XOR B, their differences illuminated: %d\n", a ^ b);
  printf("A OR B, their union revealed: %d\n", a | b);

  // Weaving a Tapestry of Bitwise Magic
  printf("In a tapestry of bits, we weave wonders\n");
  int bitmap = 0b101101;
  printf("The bitmap, a canvas of ones and zeros: %d\n", bitmap);
  printf("Setting the 5th bit, a touch of binary artistry: %d\n", bitmap | (1 << 4));
  printf("Clearing the 3rd bit, a stroke of precision: %d\n", bitmap & ~(1 << 2));
  printf("Toggling the 7th bit, a dance of opposites: %d\n", bitmap ^ (1 << 6));

  // Transcending the Boundaries of Integers
  printf("Beyond integers, bits empower us to explore the unknown\n");
  float f = 123.45;
  *(uint32_t *)&f ^= 0x80000000;
  printf("Negating the floating-point number, a flip of the sign bit: %f\n", f);

  // A Farewell to the Realm of Bits
  printf("As we bid farewell to this enigmatic realm\n");
  printf("May the lessons of bitwise manipulation forever guide our path\n");
  printf("In the symphony of bits, we find harmony and power\n");
  printf("May its echoes continue to inspire and illuminate our digital journeys\n");

  return 0;
}