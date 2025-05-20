//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: ultraprecise
#define _CRT_SECURE_NO_WARNINGS
#define BITS_PER_DAY 24 * 60 * 60
#define LEAP_YEAR(y) ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))

typedef struct {
    unsigned int year;
    unsigned char month;
    unsigned char day;
} date_t;

typedef struct {
    unsigned int days[2][31];
    unsigned int months[12];
} calendar_t;

static calendar_t calendar = {
    {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    },
    {
        0, 31, 59, 93, 122, 153, 182, 213, 244, 274, 305, 335
    }
};

date_t string_to_date(const char* str) {
    date_t date;
    sscanf(str, "%d/%d/%d", &date.day, &date.month, &date.year);
    return date;
}

unsigned int date_to_unix(const date_t* date) {
    unsigned int y = date->year;
    unsigned int m = date->month;
    unsigned int d = date->day;

    unsigned int day_number = d;
    if (LEAP_YEAR(y)) {
        if (m > 2)
            day_number += calendar.months[m - 1] + d;
        else
            day_number += calendar.months[m] + d - 1;
    } else {
        day_number += calendar.months[m - 1] + d;
    }

    return (unsigned int)((y - 1970) * 365 * BITS_PER_DAY +
                          (y - 1969) / 4 * BITS_PER_DAY +
                          (365 * day_number / 100 + day_number / 4 - 61) / 7 * BITS_PER_DAY +
                          day_number % 7 * BITS_PER_DAY);
}

int main() {
    const char* date_str = "31/12/2022";
    date_t date = string_to_date(date_str);
    unsigned int unix_timestamp = date_to_unix(&date);

    printf("Date: %d/%d/%d, Unix timestamp: %u\n", date.day, date.month, date.year, unix_timestamp);

    return 0;
}