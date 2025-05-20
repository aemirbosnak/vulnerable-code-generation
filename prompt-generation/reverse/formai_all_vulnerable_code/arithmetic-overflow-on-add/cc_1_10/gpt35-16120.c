//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TERM 100

int main(int argc, char *argv[]) {
    int n, i;
    long long fib[MAX_TERM];
    double mean, variance, stddev;

    // Generate Fibonacci sequence
    fib[0] = 0;
    fib[1] = 1;
    for (n = 2; n < MAX_TERM; n++) {
        fib[n] = fib[n-1] + fib[n-2];
        if (fib[n] < 0) {
            printf("Overflow error: Fibonacci sequence too large.\n");
            exit(1);
        }
    }

    // Compute mean, variance, and standard deviation
    mean = 0.0;
    for (i = 0; i < n; i++) {
        mean += (double)fib[i];
    }
    mean /= (double)n;

    variance = 0.0;
    for (i = 0; i < n; i++) {
        variance += pow((double)fib[i] - mean, 2.0);
    }
    variance /= (double)n;

    stddev = sqrt(variance);

    // Generate histogram of Fibonacci sequence
    FILE *hist_data = fopen("fib_hist.dat", "w");
    for (i = 0; i < n; i++) {
        fprintf(hist_data, "%lld\n", fib[i]);
    }
    fclose(hist_data);

    FILE *gnuplot = popen("gnuplot -persist", "w");
    fprintf(gnuplot, "set title \"Histogram of Fibonacci Sequence\"\n");
    fprintf(gnuplot, "set xlabel \"Fibonacci Term\"\n");
    fprintf(gnuplot, "set ylabel \"Frequency\"\n");
    fprintf(gnuplot, "set style fill solid\n");
    fprintf(gnuplot, "binwidth=100\n");
    fprintf(gnuplot, "bin(x,width)=width*floor(x/width)\n");
    fprintf(gnuplot, "plot \"fib_hist.dat\" using (bin($1,binwidth)):(1.0) smooth freq with boxes\n");
    pclose(gnuplot);

    // Generate bar chart of statistical measures
    FILE *bar_data = fopen("fib_bar.dat", "w");
    fprintf(bar_data, "Mean\t%lf\n", mean);
    fprintf(bar_data, "Variance\t%lf\n", variance);
    fprintf(bar_data, "Standard Deviation\t%lf\n", stddev);
    fclose(bar_data);

    gnuplot = popen("gnuplot -persist", "w");
    fprintf(gnuplot, "set title \"Statistical Measures of Fibonacci Sequence\"\n");
    fprintf(gnuplot, "set style data histograms\n");
    fprintf(gnuplot, "set style histogram rowstacked\n");
    fprintf(gnuplot, "set boxwidth 0.5 relative\n");
    fprintf(gnuplot, "set xtics rotate by -45\n");
    fprintf(gnuplot, "set key invert reverse Left outside\n");
    fprintf(gnuplot, "plot \"fib_bar.dat\" using 2:xtic(1) title \"Fibonacci\" lw 2\n");
    pclose(gnuplot);

    return 0;
}