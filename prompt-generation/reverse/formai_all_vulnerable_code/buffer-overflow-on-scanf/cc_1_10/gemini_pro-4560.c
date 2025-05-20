//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: introspective
#include <math.h>
#include <stdio.h>

int main() {
    // Define some constants
    const double E = 2.7182818284590452353602874713527;
    const double PI = 3.1415926535897932384626433832795;

    // Get some input from the user
    printf("Enter a number: ");
    double x;
    scanf("%lf", &x);

    // Perform some mathematical operations on the input
    double y = sin(x);
    double z = cos(x);
    double w = tan(x);
    double u = log(x);
    double v = log10(x);
    double a = pow(x, 2);
    double b = sqrt(x);
    double c = cbrt(x);
    double d = exp(x);
    double f = fabs(x);
    double g = floor(x);
    double h = ceil(x);
    double i = round(x);
    double j = trunc(x);
    double k = fmod(x, 2);
    double l = remainder(x, 2);
    double m = copysign(1.0, x);
    double n = nextafter(x, 1.0);
    double o = fmax(x, 2.0);
    double p = fmin(x, 2.0);
    double q = fdim(x, 2.0);
    double r = hypot(x, 2.0);

    // Print the results
    printf("sin(x) = %lf\n", y);
    printf("cos(x) = %lf\n", z);
    printf("tan(x) = %lf\n", w);
    printf("log(x) = %lf\n", u);
    printf("log10(x) = %lf\n", v);
    printf("x^2 = %lf\n", a);
    printf("sqrt(x) = %lf\n", b);
    printf("cbrt(x) = %lf\n", c);
    printf("exp(x) = %lf\n", d);
    printf("fabs(x) = %lf\n", f);
    printf("floor(x) = %lf\n", g);
    printf("ceil(x) = %lf\n", h);
    printf("round(x) = %lf\n", i);
    printf("trunc(x) = %lf\n", j);
    printf("fmod(x, 2) = %lf\n", k);
    printf("remainder(x, 2) = %lf\n", l);
    printf("copysign(1.0, x) = %lf\n", m);
    printf("nextafter(x, 1.0) = %lf\n", n);
    printf("fmax(x, 2.0) = %lf\n", o);
    printf("fmin(x, 2.0) = %lf\n", p);
    printf("fdim(x, 2.0) = %lf\n", q);
    printf("hypot(x, 2.0) = %lf\n", r);

    return 0;
}