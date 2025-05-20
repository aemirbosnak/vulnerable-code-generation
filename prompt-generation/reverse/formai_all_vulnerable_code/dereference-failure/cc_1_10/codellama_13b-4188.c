//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: paranoid
/*
 * Paranoid Unit Converter
 *
 * This program converts units of measurement from one to another in a paranoid manner.
 *
 * Usage:
 *   ./paranoid_unit_converter [options] <value> <from_unit> <to_unit>
 *
 * Options:
 *   -h, --help    Print this help message and exit
 *   -v, --version Print version information and exit
 *
 * Units:
 *   - Length:
 *     cm, m, km, in, ft, yd
 *   - Mass:
 *     g, kg, lb, t
 *   - Time:
 *     s, min, h, d, w, y
 *   - Temperature:
 *     C, F, K
 *
 * Example:
 *   ./paranoid_unit_converter 5 cm in
 *   ./paranoid_unit_converter 10 kg ft
 *   ./paranoid_unit_converter 300 w d
 *   ./paranoid_unit_converter 200 C F
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LEN 128

typedef enum {
  UNKNOWN,
  CM,
  M,
  KM,
  IN,
  FT,
  YD,
  G,
  KG,
  LB,
  T,
  S,
  MIN,
  H,
  D,
  W,
  Y,
  C,
  F,
  K
} unit_t;

typedef struct {
  unit_t from;
  unit_t to;
  double value;
} conversion_t;

const char* unit_strings[] = {
  "unknown",
  "cm",
  "m",
  "km",
  "in",
  "ft",
  "yd",
  "g",
  "kg",
  "lb",
  "t",
  "s",
  "min",
  "h",
  "d",
  "w",
  "y",
  "C",
  "F",
  "K"
};

const double unit_factors[] = {
  1.0,
  0.01,
  0.001,
  0.000001,
  0.393700787,
  0.0254,
  0.9144,
  0.001,
  0.000001,
  0.0000000045359237,
  0.001,
  0.0166666667,
  0.0002777778,
  0.0000166667,
  0.000000027,
  0.00000000000166667,
  1.0,
  1.8,
  1.0,
  1.0
};

int get_unit_from_string(const char* str) {
  for (int i = 0; i < sizeof(unit_strings) / sizeof(unit_strings[0]); i++) {
    if (strcmp(str, unit_strings[i]) == 0) {
      return i;
    }
  }
  return UNKNOWN;
}

double convert_unit(double value, unit_t from, unit_t to) {
  return value * unit_factors[to] / unit_factors[from];
}

int main(int argc, char** argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
    return 1;
  }

  double value = atof(argv[1]);
  unit_t from = get_unit_from_string(argv[2]);
  unit_t to = get_unit_from_string(argv[3]);

  if (from == UNKNOWN || to == UNKNOWN) {
    fprintf(stderr, "Unknown unit: %s or %s\n", argv[2], argv[3]);
    return 1;
  }

  double result = convert_unit(value, from, to);

  printf("%f %s = %f %s\n", value, unit_strings[from], result, unit_strings[to]);

  return 0;
}